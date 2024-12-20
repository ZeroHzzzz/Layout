// #include <algorithm>
// #include <ftxui/component/component.hpp>
// #include <ftxui/component/screen_interactive.hpp>
// #include <ftxui/dom/elements.hpp>
// #include <sstream>
// #include <vector>

// using namespace ftxui;

// int main() {
//     std::string input = "";
//     std::vector<int> data;

//     auto render_bar_chart = [&]() {
//         std::vector<Element> bars;
//         int max_height = 10;  // 最大显示高度
//         if (!data.empty()) {
//             int max_value = *std::max_element(data.begin(), data.end());
//             for (int& value : data) {
//                 value = max_value > max_height ? value * max_height /
//                 max_value
//                                                : value;
//             }
//         }

//         for (int value : data) {
//             std::string result(value, '#');
//             bars.push_back(hbox({
//                 text(std::to_string(value)),  // 显示数值
//                 text(result),
//             }));
//         }
//         return vbox(std::move(bars)) | center | border;
//     };

//     auto screen = ScreenInteractive::TerminalOutput();

//     auto input_component = Input(&input, "Enter numbers");
//     auto submit_button = Button("Submit", [&]() {
//         std::stringstream ss(input);
//         data.clear();
//         int value;
//         while (ss >> value) {
//             if (value > 0) {  // 过滤负数
//                 data.push_back(value);
//             }
//         }
//     });

//     auto layout = Container::Vertical({
//         input_component,
//         submit_button,
//     });

//     auto renderer = Renderer(layout, [&]() {
//         return vbox({text("Dynamic Bar Chart") | bold | center,
//                      render_bar_chart(),
//                      hbox({
//                          text("Input: "),
//                          input_component->Render(),
//                          submit_button->Render(),
//                      }) | border});
//     });

//     screen.Loop(renderer);

//     return 0;
// }
