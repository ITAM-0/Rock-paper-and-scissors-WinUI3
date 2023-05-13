// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "MainWindow.g.h"

namespace winrt::Rock_paper_and_scissors_Game::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void myButton_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::Rock_paper_and_scissors_Game::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
