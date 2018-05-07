class RandomizedSet {
    public:
        /** Initialize your data structure here. */
        RandomizedSet() {
            srand(time(NULL));
        }

        /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
        bool insert(int val) {
            if (m_s.count(val) > 0)
                return false;

            m_v.push_back(val);
            m_s[val] = m_v.size() - 1;
            return true;
        }

        /** Removes a value from the set. Returns true if the set contained the specified element. */
        bool remove(int val) {
            if (m_s.count(val) == 0)
                return false;

            int index = m_s[val];
            m_s.erase(val);
            m_v[index] = m_v[m_v.size() - 1];
            m_v.pop_back();

            if (index < m_v.size())
                m_s[m_v[index]] = index;

            return true;
        }

        /** Get a random element from the set. */
        int getRandom() {
            return m_v[rand() % m_v.size()];
        }

    private:
        unordered_map<int, int> m_s;
        vector<int> m_v;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
