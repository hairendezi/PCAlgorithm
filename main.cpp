#include "Elementary.h"
#include "utils.h"

int main() {
    FILE * fp = fopen("D:\\Desktop\\Project\\C\\PCAlgorithm\\data\\rules\\acl\\1k\\dataacl1k1-1", "r");
    vector<Rule5> ruleList = loadRule5(fp);
    cout << ruleList.size() << endl;
    for(auto rule : ruleList) {
        rule.printRule();
    }
}
