class ProductOfNumbers {
public:
    vector<int> v;

    ProductOfNumbers() {
        v = {1};
    }

    void add(int num) {
        if (num == 0) {
            v = {1};               // everything before this zero is irrelevant
        } else {
            v.push_back(v.back() * num);
        }
    }

    int getProduct(int k) {
        if (k >= v.size()) return 0;   // window includes a zero
        return v.back() / v[v.size() - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */