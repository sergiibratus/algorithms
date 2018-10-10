class Solution {
public:
	struct Interval {
		Interval(int l, int r, int h) { left = l; right = r; height = h; }
		int left, right, height;

		bool operator< (const Interval& rhs) {
			return left < rhs.left;
		}
	};

	vector<int> fallingSquares(vector<pair<int, int> >& positions) {
		vector<Interval> v;
		vector<int> result;
		int current = INT_MIN;

		for (auto val : positions) {
			int left = val.first;
			int right = val.first + val.second;
			int height = val.second;

			auto begin = lower_bound(v.begin(), v.end(), left,
				[this](const Interval& p, int value) {
				return p.right <= value;
			});

			auto end = upper_bound(v.begin(), v.end(), right,
				[](int value, const Interval& p) {
				return p.left >= value;
			});

			for (auto it = begin; it != end; ++it)
				height = max(height, it->height + val.second);

			vector<Interval> vec;
			if (begin != v.end() && begin->left < left)
				vec.emplace_back(begin->left, left, begin->height);

			vec.emplace_back(left, right, height);

			for (auto it = begin; it != end; ++it)
				if (it->right > right)
					vec.emplace_back(right, it->right, it->height);

			end = v.erase(begin, end);
			v.insert(end, vec.begin(), vec.end());

			current = max(current, height);
			result.push_back(current);
		}

		return result;
	}
};