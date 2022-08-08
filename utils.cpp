#include "utils.h"

vector<Rule5> loadRule5(FILE *fp) {
    uint32_t temp;
    uint32_t sip1, sip2, sip3, sip4, smask;
    uint32_t dip1, dip2, dip3, dip4, dmask;
    uint32_t sport1, sport2;
    uint32_t dport1, dport2;
    uint32_t protocal, protocol_mask;
    uint32_t ht, htmask;
    int ruleNum = 0;
    vector<Rule5> ruleList;
    while (true) {
        Rule5 r;
        uint32_t lRP, rRP;
        if (fscanf(
                fp,
                "@%d.%d.%d.%d/%d\t%d.%d.%d.%d/%d\t%d : %d\t%d : %d\t%x/%x\t%x/%x\n",
                &sip1, &sip2, &sip3, &sip4, &smask,
                &dip1, &dip2, &dip3, &dip4, &dmask,
                &sport1, &sport2,
                &dport1, &dport2,
                &protocal, &protocol_mask,
                &ht, &htmask
        ) != 18) {
            break;
        }
        // Source IP
        temp = (sip1 << 24) | (sip2 << 16) | (sip3 << 8) | sip4;
        lRP = temp & (~((1 << (32 - smask)) - 1));
        rRP = temp | ((1 << (32 - smask)) - 1);
        r.range[0][0] = lRP;
        r.range[0][1] = rRP;
        r.mask[0] = smask;

        // Destination IP]
        temp = (dip1 << 24) | (dip2 << 16) | (dip3 << 8) | dip4;
        lRP = temp & (~((1 << (32 - dmask)) - 1));
        rRP = temp | ((1 << (32 - dmask)) - 1);
        r.range[1][0] = lRP;
        r.range[1][1] = rRP;
        r.mask[1] = dmask;

        // Source Port
        r.range[2][0] = sport1;
        r.range[2][1] = sport2;
        r.mask[2] = 0;
        for (int i = 15; i >= 0; i--) {
            unsigned int Bit = 1 << i;
            unsigned int sp = sport1 ^ sport2;
            if (sp & Bit) {
                break;
            }
            r.mask[2]++;
        }

        // Destination Port
        r.range[3][0] = dport1;
        r.range[3][1] = dport2;
        r.mask[3] = 0;
        for (int i = 15; i >= 0; i--) {
            unsigned int Bit = 1 << i;
            unsigned int dp = dport1 ^ dport2;
            if (dp & Bit) {
                break;
            }
            r.mask[3]++;
        }

        if (protocol_mask == 0xFF) {
            lRP = protocal;
            rRP = protocal;
            r.mask[4] = 8;
        } else if (protocol_mask == 0) {
            lRP = 0;
            rRP = 0xFF;
        } else {
            printf("Protocol mask error\n");
            exit(-1);
        }
        r.range[4][0] = lRP;
        r.range[4][1] = rRP;

        r.id = ruleNum;

        ruleList.push_back(r);
        ruleNum++;
    }

    int maxPri = ruleNum - 1;
    for (int i = 0; i < ruleNum; i++) {
        ruleList[i].priority = maxPri - i;
    }
    return ruleList;
}