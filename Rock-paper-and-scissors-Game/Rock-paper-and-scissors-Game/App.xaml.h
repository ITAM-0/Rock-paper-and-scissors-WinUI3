// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "App.xaml.g.h"

namespace winrt::Rock_paper_and_scissors_Game::implementation
{
    struct App : AppT<App>
    {
        App();

        void OnLaunched(Microsoft::UI::Xaml::LaunchActivatedEventArgs const&);

    private:
        winrt::Microsoft::UI::Xaml::Window window{ nullptr };
    };
}
