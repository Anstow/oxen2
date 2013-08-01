#ifndef OXENGINE_STATE_HPP
#define OXENGINE_STATE_HPP

namespace oxEngine {

class State {
public:
    State();
    ~State();

    void createSubstate();

    void update(unsigned int time);

    virtual void onStated() = 0;
    virtual void onPaused() = 0;
    virtual void onStoped() = 0;

    void addMenu();
    void removeMenu();
};

} // namespace oxEngine

#endif // OXENGINE_STATE_HPP
