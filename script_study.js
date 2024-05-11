const cal_study = new CalHeatmap();
cal_study.paint(
    {
        itemSelector: "#cal-study-heatmap",
        data: {
            source: "./records/study_track.csv",
            type: "csv",
            x: "date",
            y: "topic",
            groupY: d => d[0],
        },
        date: {
            start: new Date("2024-01-01"),
            locale: { weekStart: 1 }
        },
        range: 1,
        scale: {
            color: {
                type: "ordinal",
                range: ["#666666", "#e6ab02", "#e7298a", "#1b9e77"],
                domain: ['nothing', 'reading', 'coding', 'watching'],
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
            Tooltip,
            {
                text: function (date, value, dayjsDate) {
                    return dayjsDate.format("LL");
                },
            },
        ],
        [
            Legend,
            {
                tickSize: 5,
                width: 250,
                itemSelector: "#study-legend",
            },
        ],
    ]
);
