class ProductOfNumbers {
public:
    vector<int> prefixProduct;
    int lastZeroIndex;

    ProductOfNumbers() {
        prefixProduct.push_back(1);
        lastZeroIndex = -1;
    }
    
    void add(int num) {
        if (num == 0) {
            prefixProduct.clear();
            prefixProduct.push_back(1);
            lastZeroIndex = prefixProduct.size();  
        } else {
            prefixProduct.push_back(prefixProduct.back() * num);
        }
    }
    
    int getProduct(int k) {
        if (k >= prefixProduct.size()) {
            return 0;
        }
        return prefixProduct.back() / prefixProduct[prefixProduct.size() - k - 1];
    }
};
