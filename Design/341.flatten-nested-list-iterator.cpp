class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; --i) {
           nestedStack.push(nestedList[i]);
        }
    }

    int next() {
        int result = nestedStack.top().getInteger();
        nestedStack.pop();
        return result;
    }

    bool hasNext() {
        if (nestedStack.empty()) return false;
        NestedInteger stackTop;
        while (!(stackTop = nestedStack.top()).isInteger()) {
            nestedStack.pop();
            vector<NestedInteger> topList = stackTop.getList();
            for (int i = topList.size() - 1; i >= 0; --i) {
                nestedStack.push(topList[i]);
            }
            if (nestedStack.empty()) return false;
        }
        return true;
    }
private:
    stack<NestedInteger> nestedStack;
};