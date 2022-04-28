#include <vector>
#include <string>

class Hilb{
    private:
        int order_count;
        std::string file_name;
        //2d vector that will store pixels values that will ultimately be the output
        std::vector<std::vector<int> > hilb_vec;
        std::vector<int> point_vec;

    public:
        Hilb(int order, std::string fname);
        void init_vec();
        void connect_points();
        int main_func(int i, int j, int i2, int j2, int i3, int j3, int count);
        void output_file();
};
