#ifndef FTXUI_LAYOUT_HPP
#define FTXUI_LAYOUT_HPP

#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>

using namespace ftxui;

class Layout {
   public:
    Layout() = default;

    // 渲染界面
    void Run() {
        auto screen = ScreenInteractive::Fullscreen();
        screen.Loop(Render());
    }

   private:
    // 左侧算法列表 - 改为 Checkbox
    Component AlgorithmList() {
        auto checkbox_entries = std::array<std::string, 3>{
            "Algorithm 1", "Algorithm 2", "Algorithm 3"};
        auto checkbox_states = std::array<bool, 3>{false, false, false};

        auto checkbox_container = Container::Vertical({});
        for (size_t i = 0; i < checkbox_entries.size(); ++i) {
            checkbox_container->Add(
                Checkbox(checkbox_entries[i], &checkbox_states[i]));
        }

        // 返回整个容器，而不是仅仅是一个 Renderer
        return checkbox_container;
    }

    // 中间算法过程输出
    Component ProcessOutput() {
        return Renderer(
            [] { return text("算法过程输出（后续实现）") | border; });
    }

    // 右上需要排序的数组输入
    Component InputArray() {
        return Renderer([] { return text("需要排序的数组输入") | border; });
    }

    // 右下指标输出
    Component MetricsOutput() {
        return Renderer([] { return text("指标输出，后续实现") | border; });
    }

    // 底部设置
    Component Settings() {
        return Renderer([] { return text("Settings") | border; });
    }

    // 布局实现
    Component Render() {
        // 主容器：包含所有子组件
        auto main_container = Container::Vertical({
            AlgorithmList(),
            ProcessOutput(),
            InputArray(),
            MetricsOutput(),
            Settings(),
        });

        return Renderer(main_container, [&] {
            return vbox({
                hbox({
                    // 左侧 algorithm list
                    window(text(" algorithm list "),
                           AlgorithmList()->Render()) |
                        size(WIDTH, EQUAL, 20),

                    // 中部 算法过程输出
                    window(text(" 算法过程输出（后续实现） "),
                           ProcessOutput()->Render()) |
                        flex,

                    // 右侧 需要排序的数组 & 指标输出
                    vbox({
                        window(text(" 需要排序的数组输入 "),
                               InputArray()->Render()),
                        window(text(" 指标输出，后续实现 "),
                               MetricsOutput()->Render()),
                    }) | size(WIDTH, EQUAL, 30),
                }) | flex,

                // 底部 Settings
                window(text(" Settings "), Settings()->Render()) |
                    size(HEIGHT, EQUAL, 3),
            });
        });
    }
};

#endif  // FTXUI_LAYOUT_HPP
