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
        date: {
            start: new Date("2024-01-01"),
            locale: { weekStart: 1 }
        },
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
        subDomain: {
            type: "day",
            radius: 3,
            gutter: 4,
            height: 15,
            width: 15,
            label: function (timestamp, value) {
                const currentDate = new Date();
                const today = currentDate.toDateString();

                const received_ts = new Date(timestamp);
                const received_date = received_ts.toDateString();
                // console.log(today);
                // console.log(received_date);
                let result = today.localeCompare(received_date);
                if (result == 0) {
                    return "🟨";
                } else {
                    return "";
                }
            },
        },
    },
    [
        [
            Legend,
            {
                tickSize: 5,
                width: 250,
                itemSelector: "#gym-legend",
                label: "energy level",
            },
        ],
        [
            Tooltip,
            {
                // enabled: false,
                text: function (date, value, dayjsDate) {
                    return (
                        (value ? value + "/5" : "No data") + " on " + dayjsDate.format("LL")
                    );
                },
            },
        ],
        // [
        //     CalendarLabel,
        //     {
        //         key: 'gym_label',
        //         width: 40,
        //         textAlign: "middle",
        //         text: () => dayjs.weekdaysShort().map((d, i) => (i % 2 == 0 ? "" : d)),
        //     },
        // ],
    ]
);
