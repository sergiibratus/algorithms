class RangeModule {
public:
    RangeModule() {
    }

    void addRange(int left, int right) {
        ValT comp = make_pair(left, 0);
        auto it = lower_bound(m_int.begin(), m_int.end(), comp, [](const ValT& left, const ValT& right) {
            return left.first < right.first;
        });
        if (it == m_int.end()) {
            if (!m_int.empty() && (it - 1)->second >= left) {
                --it;
                it->second = max(it->second, right);
                return;
            } else {
                m_int.emplace_back(left, right);
            }
            
            return;
        }
        if (it != m_int.begin()) {
            --it;
            if (it->second < left)
                ++it;
        }

        if (it->first > right) {
            m_int.emplace(it, left, right);
            return;
        }

        auto it_end = it;
        it_end++;
        while (it_end != m_int.end() && it_end->first <= right) {
            right = max(right, it_end->second);
            it_end = m_int.erase(it_end);
        }
        it->first = min(it->first, left);
        it->second = max(it->second, right);
    }

    bool queryRange(int left, int right) {
        if (m_int.empty())
            return false;

        ValT comp = make_pair(left, 0);
        auto it = lower_bound(m_int.begin(), m_int.end(), comp, [](const ValT& left, const ValT& right) {
            return left.first < right.first;
        });

        if (it == m_int.end()) {
            --it;
        }
        else {
            if (it->first <= left && it->second >= right)
                return true;

            if (it == m_int.begin())
                return false;

            --it;
        }

        return (it->first <= left && it->second >= right);
    }

    void removeRange(int left, int right) {
        ValT comp = make_pair(left, 0);
        auto it = lower_bound(m_int.begin(), m_int.end(), comp, [](const ValT& left, const ValT& right) {
            return left.first < right.first;
        });
        if (it == m_int.end()) {
            if (!m_int.empty() && (it - 1)->second > left) {
                --it;

                int old_sec = it->second;
                it->second = left;

                if (old_sec > right)
                    m_int.push_back(make_pair(right, old_sec));
            }

            return;
        }
        
        if (it != m_int.begin()) {
            --it;
            if (it->second <= left) {
                ++it;
            }
        }

        if (it->first >= right)
            return;

        if (it->first < left && it->second > right) {
            int old = it->second;
            it->second = left;
            ++it;
            m_int.insert(it, make_pair(right, old));
            return;
        }

        if (it->first < left) {
            it->second = min(it->second, left);
            it++;
        }

        while (it != m_int.end() && it->second <= right) {
            it = m_int.erase(it);
        }

        if (it != m_int.end() && it->first < right)
            it->first = right;
    }
private:
    typedef pair<int, int> ValT;
    vector<ValT> m_int;
};