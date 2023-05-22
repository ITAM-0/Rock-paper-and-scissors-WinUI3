using Microsoft.UI;
using Microsoft.UI.Xaml;
// using Microsoft.UI.Xaml.Controls;
// using Microsoft.UI.Xaml.Controls.Primitives;
// using Microsoft.UI.Xaml.Data;
// using Microsoft.UI.Xaml.Input;
using Microsoft.UI.Xaml.Media;
using Microsoft.UI.Xaml.Media.Imaging;
// using Microsoft.UI.Xaml.Navigation;
using System;
// using System.Collections.Generic;
// using System.IO;
// using System.Linq;
// using System.Runtime.InteropServices.WindowsRuntime;
// using System.Text.RegularExpressions;
// using Windows.ApplicationModel.Core;
// using Windows.Foundation;
// using Windows.Foundation.Collections;

// ========================================================================


namespace Rock_paper_and_scissors_Game
{

    public sealed partial class MainWindow : Window
    {
        public MainWindow()
        {
            this.InitializeComponent();
            // Title bar settings
            Title = "Rock paper and scissors";
            ExtendsContentIntoTitleBar = true;
            SetTitleBar(AppTitleBar);
        }

        // Variables of players game results
        int p1Count = 0;
        int p2Count = 0;

        // Player move selection variables
        int p1Choice = 0;
        int p2Choice = 0;

        // A function that updates the hand images in the user interface
        public void updatePhotos(int p1, int p2)
        {
            // P1 Image change
            switch (p1)
            {
                // Rock image
                case 1:
                    p1Icon.Source = new BitmapImage(new Uri("ms-appx:///Assets/Rock_left.jpg"));
                    break;
                // Paper image
                case 2:
                    p1Icon.Source = new BitmapImage(new Uri("ms-appx:///Assets/Paper_left.jpg"));
                    break;
                // Scissors image
                case 3:
                    p1Icon.Source = new BitmapImage(new Uri("ms-appx:///Assets/Scissors_left.jpg"));
                    break;
            }

            // P2 Image change
            switch (p2)
            {
                // Rock image
                case 1:
                    p2Icon.Source = new BitmapImage(new Uri("ms-appx:///Assets/Rock_right.jpg"));
                    break;
                // Paper image
                case 2:
                    p2Icon.Source = new BitmapImage(new Uri("ms-appx:///Assets/Paper_right.jpg"));
                    break;
                // Scissors image
                case 3:
                    p2Icon.Source = new BitmapImage(new Uri("ms-appx:///Assets/Scissors_right.jpg"));
                    break;
            }
        }

        // Function that checks who won and sets the result
        public void Win()
        {
            // Draw
            if (p1Choice == p2Choice)
            {
                LabelResult.Text = "DRAW";
                p1Line.Background = new SolidColorBrush(Colors.Orange);
                p2Line.Background = new SolidColorBrush(Colors.Orange);
            }
            // Win player 1
            else if (p1Choice == 1 && p2Choice == 3)
            {
                LabelResult.Text = "You Win";
                p1Count++;
                p1Result.Text = "You : " + p1Count.ToString();
                p1Line.Background = new SolidColorBrush(Colors.Green);
                p2Line.Background = new SolidColorBrush(Colors.Red);
            }
            // Win player 1
            else if (p1Choice == 2 && p2Choice == 1)
            {
                LabelResult.Text = "You Win";
                p1Count++;
                p1Result.Text = "You : " + p1Count.ToString();
                p1Line.Background = new SolidColorBrush(Colors.Green);
                p2Line.Background = new SolidColorBrush(Colors.Red);
            }
            // Win player 1
            else if (p1Choice == 3 && p2Choice == 2)
            {
                LabelResult.Text = "You Win";
                p1Count++;
                p1Result.Text = "You : " + p1Count.ToString();
                p1Line.Background = new SolidColorBrush(Colors.Green);
                p2Line.Background = new SolidColorBrush(Colors.Red);
            }
            // Win player 2
            else
            {
                LabelResult.Text = "CPU Win";
                p2Count++;
                p2Result.Text = p2Count.ToString() + " : CPU";
                p1Line.Background = new SolidColorBrush(Colors.Red);
                p2Line.Background = new SolidColorBrush(Colors.Green);
            }
        }

        // Main game management function
        public void Game(int x)
        {
            Random rnd = new Random();
            // Player movement selection settings
            p1Choice = x; 
            p2Choice = rnd.Next(1, 4);
            // Image setting
            updatePhotos(p1Choice, p2Choice);
            Win();
        }

        // Rock Click button
        private void Rock_Click(object sender, RoutedEventArgs e)
        {
            Game(1);
        }

        // Paper Click button
        private void Paper_Click(object sender, RoutedEventArgs e)
        {
            Game(2);
        }

        // Scissors Click button
        private void Scissors_Click(object sender, RoutedEventArgs e)
        {
            Game(3);
        }

        // Game reset
        private void Reset_Click(object sender, RoutedEventArgs e)
        {
            // Resetting the game
            p1Count = 0;
            p2Count = 0;
            p1Result.Text = "You : " + p1Count.ToString();
            p2Result.Text = p1Count.ToString() + " : CPU";
            LabelResult.Text = "";
            p1Line.Background = new SolidColorBrush(Colors.Blue);
            p2Line.Background = new SolidColorBrush(Colors.Blue);
            updatePhotos(2, 2);
        }
    }

    // ========================================================================
}
