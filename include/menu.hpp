// #ifndef FTXUI_LAYOUT_HPP
// #define FTXUI_LAYOUT_HPP

// #include <ftxui/component/component.hpp>
// #include <ftxui/component/component_base.hpp>
// #include <ftxui/component/screen_interactive.hpp>
// #include <ftxui/dom/elements.hpp>

// using namespace ftxui;

// class Layout {
//    public:
//     Layout() = default;

//     // 渲染界面
//     void Run() {
//         auto screen = ScreenInteractive::FitComponent();
//         screen.Loop(Render());
//     }

//    private:
//     // 左侧算法列表 - 改为 Checkbox
//     Component AlgorithmList() {
//         std::array<bool, 30> states;

//         auto container = Container::Vertical({});
//         for (int i = 0; i < 30; ++i) {
//             states[i] = false;
//             container->Add(
//                 Checkbox("Checkbox" + std::to_string(i), &states[i]));
//         }

//         return container;
//     }

//     // 布局实现
//     Element Render() {
//         return Renderer(AlgorithmList(), [&] {
//             return AlgorithmList()->Render() | vscroll_indicator | frame |
//                    size(HEIGHT, LESS_THAN, 10) | border;
//         });
//     };

// #endif  // FTXUI_LAYOUT_HPP
