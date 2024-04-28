const toggleButton = document.getElementById('lightDarkToggleButton');
const bodyElement = document.body;
let isDarkMode = false;

toggleButton.addEventListener('click', () => {
    bodyElement.classList.toggle('dark-mode');
    isDarkMode = bodyElement.classList.contains('dark-mode');

    const colorScheme_gym = isDarkMode ? 'GnBu' : 'BuPu';
    // color_gym_light = {
    //     type: "linear",
    //     range: ["#dadaeb", "#bcbddc", "#9e9ac8", "#807dba", "#6a51a3", "#4a1486"],
    //     domain: [0, 1, 2, 3, 4, 5],
    // };
    // color_gym_dark = {
    //     scheme: "BuPu",
    //     type: "linear",
    //     // range: ["#666666", "#867f8f", "#9380ab", "#a681d4", "#a367f0", "#8d37fa"],
    //     domain: [0, 1, 2, 3, 4, 5],
    // };
    // if (isDarkMode) {
    //     gym_options.scale.color = color_gym_dark;
    // } else {
    //     gym_options.scale.color = color_gym_light;
    // }

    gym_options.scale.color.scheme = colorScheme_gym;
    cal_gym.paint(gym_options, gym_plugs);

    const colorScheme_spoiler = isDarkMode ? 'GnBu' : 'Greys';
    spoiler_options.scale.color.scheme = colorScheme_spoiler;
    cal_spoiler.paint(
        spoiler_options, spoiler_plugs
    );
});
