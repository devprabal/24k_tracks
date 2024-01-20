const cal_gym = new CalHeatmap();
cal_gym.paint(
    {
        itemSelector: "#cal-gym-heatmap",
        data: {
            source: "./records/gym_track.csv",
            type: "csv",
            x: "date",
            y: (d) => +d["energylevel"],
            groupY: "max",
        },
        date: { start: new Date("2024-01-01") },
        range: 1,
        scale: {
            color: {
                type: "sequential",
                scheme: "Purples",
                domain: [0, 1, 2, 3, 4, 5],
            },
        },
        domain: {
            type: "year",
            label: { text: null },
        },
        subDomain: { type: "day", radius: 0 },
    },
    [
        [
            Legend,
            {
                tickSize: 0,
                width: 150,
                itemSelector: "#gym-legend",
                label: "energy level",
            },
        ],
        [
            Tooltip,
            {
                text: function (date, value, dayjsDate) {
                    return (
                        (value ? value + "/5" : "No data") + " on " + dayjsDate.format("LL")
                    );
                },
            },
        ],
        [
            CalendarLabel,
            {
                width: 30,
                textAlign: "start",
                text: () => dayjs.weekdaysShort().map((d, i) => (i % 2 == 0 ? "" : d)),
            },
        ],
    ]
);
