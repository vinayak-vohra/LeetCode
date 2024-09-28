class MyCalendar {
    map<int, int> keep;

public:
    MyCalendar() {}

    bool book(int start, int end) {
        auto b = keep.upper_bound(start);
        if (b != keep.end() && b->second < end)
            return false;
        keep[end] = start;
        return true;
    }
};