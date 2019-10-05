
// namespace
 
namespace Second {
    int i = 1;
    namespace Internal {
        struct P {
            P(int X, int Y):x(X), y(Y) {}
            int x;
            int y;
        };
    }
}
