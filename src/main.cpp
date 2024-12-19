#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <string>
#include <vector>

using namespace ftxui;

int main() {
    // 1. 定义状态变量，用于存储组件之间的数据
    std::string algorithm_selected = "None";  // 用户选择的算法
    std::string array_input = "";             // 用户输入的数组
    std::string process_output = "";          // 算法过程输出
    std::string metrics_output = "";          // 算法运行结果

    // 2. 左侧 Algorithm List
    auto algorithm_list_container = Container::Vertical({});
    for (int i = 0; i < 10; ++i) {  // 示例算法列表
        std::vector<std::string> algorithms = {
            "BubbleSort", "CustomSort", "HeapSort",  "InsertionSort",
            "Introsort",  "MergeSort",  "QuickSort", "SelectionSort",
            "ShellSort",  "TimSort"};
        algorithm_list_container->Add(
            Button(algorithms[i], [name = algorithms[i], &algorithm_selected,
                                   &process_output, &metrics_output] {
                algorithm_selected = name;  // 捕获的值是独立的
                process_output = "Running " + name + "...";
                metrics_output = "Metrics of " + name;
            }));
    }

    auto algorithm_list = Renderer(algorithm_list_container, [&] {
        return window(text(" algorithm list "),
                      algorithm_list_container->Render()) |
               size(WIDTH, EQUAL, 20);
    });

    // 3. 中间 算法过程输出（从 process_output 状态获取内容）
    auto process_output_renderer = Renderer([&] {
        return window(text(" 算法过程输出 "), text(process_output)) | flex;
    });

    // 4. 右上角 需要排序的数组输入
    auto array_input_component = Input(&array_input, "Enter array here...");
    auto array_input_renderer = Renderer(array_input_component, [&] {
        return window(text(" 需要排序的数组输入 "),
                      array_input_component->Render()) |
               size(HEIGHT, EQUAL, 8);
    });

    // 5. 右下角 指标输出（从 metrics_output 状态获取内容）
    auto metrics_output_renderer = Renderer([&] {
        return window(text(" 指标输出 "), text(metrics_output)) |
               size(HEIGHT, EQUAL, 8);
    });

    // 右侧（将右上角和右下角垂直排列）
    auto right_panel = Renderer([&] {
        return vbox({
                   array_input_renderer->Render(),
                   metrics_output_renderer->Render(),
               }) |
               size(WIDTH, EQUAL, 30);
    });

    // 6. 底部 Settings
    auto settings_renderer = Renderer([&] {
        return window(text(" Settings "),
                      text("Selected Algorithm: " + algorithm_selected)) |
               size(HEIGHT, EQUAL, 3);
    });

    // 7. 主布局：将左侧、中间和右侧水平排列，并在底部添加 Settings
    auto main_container = Container::Vertical({
        algorithm_list_container,
        array_input_component,
    });

    auto main_renderer = Renderer(main_container, [&] {
        return vbox({
            hbox({
                algorithm_list->Render(),
                process_output_renderer->Render(),
                right_panel->Render(),
            }) | flex,
            settings_renderer->Render(),
        });
    });

    // 8. 启动界面
    auto screen = ScreenInteractive::Fullscreen();
    screen.Loop(main_renderer);

    return 0;
}
