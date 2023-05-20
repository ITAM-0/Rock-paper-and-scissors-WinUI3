using Microsoft.UI;
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using Microsoft.UI.Xaml.Controls.Primitives;
using Microsoft.UI.Xaml.Data;
using Microsoft.UI.Xaml.Input;
using Microsoft.UI.Xaml.Media;
using Microsoft.UI.Xaml.Media.Imaging;
using Microsoft.UI.Xaml.Navigation;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text.RegularExpressions;
using Windows.ApplicationModel.Core;
using Windows.Foundation;
using Windows.Foundation.Collections;

// ========================================================================


namespace Rock_paper_and_scissors_Game
{

    public sealed partial class MainWindow : Window
    {
        public MainWindow()
        {
            this.InitializeComponent();

            ExtendsContentIntoTitleBar = true;
            SetTitleBar(AppTitleBar);
        }

        // https://stackoverflow.com/questions/2706500/how-do-i-generate-a-random-integer-in-c
        public int GenerateRandom(int min, int max)
        {
            var seed = Convert.ToInt32(Regex.Match(Guid.NewGuid().ToString(), @"\d+").Value);
            return new Random(seed).Next(min, max);
        }

        public static class IntUtil
        {
            private static Random random;

            private static void Init()
            {
                if (random == null) random = new Random();
            }

            public static int Random(int min, int max)
            {
                Init();
                return random.Next(min, max);
            }
        }

        int p1Count = 0;
        int p2Count = 0;

        int p1Choice = 0;
        int p2Choice = 0;

        // A function that updates the hand images in the user interface
        public void updatePhotos(int p1, int p2)
        {
            // P1 Image change
            switch (p1)
            {
                case 1:
                    p1Icon.Source = new BitmapImage(new Uri("ms-appx:///Assets/Rock_left.jpg"));
                    break;
                case 2:
                    p1Icon.Source = new BitmapImage(new Uri("ms-appx:///Assets/Paper_left.jpg"));
                    break;
                case 3:
                    p1Icon.Source = new BitmapImage(new Uri("ms-appx:///Assets/Scissors_left.jpg"));
                    break;
            }

            // P2 Image change
            switch (p2)
            {
                case 1:
                    p2Icon.Source = new BitmapImage(new Uri("ms-appx:///Assets/Rock_right.jpg"));
                    break;
                case 2:
                    p2Icon.Source = new BitmapImage(new Uri("ms-appx:///Assets/Paper_right.jpg"));
                    break;
                case 3:
                    p2Icon.Source = new BitmapImage(new Uri("ms-appx:///Assets/Scissors_right.jpg"));
                    break;
            }
        }

        public void Win()
        {
            if (p1Choice == p2Choice)
            {
                LabelResult.Text = "DRAW";
                p1Line.Background = new SolidColorBrush(Colors.Orange);
                p2Line.Background = new SolidColorBrush(Colors.Orange);
            }
            else if (p1Choice == 1 && p2Choice == 3)
            {
                LabelResult.Text = "You Win";
                p1Count++;
                p1Result.Text = "You : "+p1Count.ToString();
                p1Line.Background = new SolidColorBrush(Colors.Green);
                p2Line.Background = new SolidColorBrush(Colors.Red);
            }
            else if (p1Choice == 2 && p2Choice == 1)
            {
                LabelResult.Text = "You Win";
                p1Count++;
                p1Result.Text = "You : " + p1Count.ToString();
                p1Line.Background = new SolidColorBrush(Colors.Green);
                p2Line.Background = new SolidColorBrush(Colors.Red);
            }
            else if (p1Choice == 3 && p2Choice == 2)
            {
                LabelResult.Text = "You Win";
                p1Count++;
                p1Result.Text = "You : " + p1Count.ToString();
                p1Line.Background = new SolidColorBrush(Colors.Green);
                p2Line.Background = new SolidColorBrush(Colors.Red);
            }
            else
            {
                LabelResult.Text = "CPU Win";
                p2Count++;
                p2Result.Text = p2Count.ToString()+" : CPU";
                p1Line.Background = new SolidColorBrush(Colors.Red);
                p2Line.Background = new SolidColorBrush(Colors.Green);
            }

        }

        public void Game(int x)
        {
            p1Choice = x;
            p2Choice = IntUtil.Random(1, 4);
            updatePhotos(p1Choice, p2Choice);
            Win();
        }

        private void Rock_Click(object sender, RoutedEventArgs e)
        {
            Game(1);
        }

        private void Paper_Click(object sender, RoutedEventArgs e)
        {
            Game(2);
        }

        private void Scissors_Click(object sender, RoutedEventArgs e)
        {
            Game(3);
        }

        // Game reset
        private void Reset_Click(object sender, RoutedEventArgs e)
        {
            p1Count = 0;
            p2Count = 0;
            p1Result.Text = "You: " + p1Count.ToString();
            p2Result.Text = p1Count.ToString()+" :CPU";
            LabelResult.Text = "";
            p1Line.Background = new SolidColorBrush(Colors.Blue);
            p2Line.Background = new SolidColorBrush(Colors.Blue);
            updatePhotos(2, 2);
        }
    }

    // ========================================================================
}
