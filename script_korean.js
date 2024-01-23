const cal_korean = new CalHeatmap();
cal_korean.paint(
    {
        itemSelector: "#cal-korean-heatmap",
        data: {
            source: "./records/korean_track.csv",
            type: "csv",
            x: "date",
            y: "topic",
            groupY: d => d[0],
        },
        date: { start: new Date("2024-01-01") },
        range: 1,
        scale: {
            color: {
                type: "ordinal",
                // scheme: "Dark2 ",
                range: ["#666666", "#e6ab02", "#e7298a", "#1b9e77"],
                domain: ['nothing', 'only_immersion', 'only_study', 'study_immersion'],
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
                    // var result_string = '';
                    // if(value == 1) {
                    //     result_string.append("only study");
                    // } else if (value == 2) {
                    //     result_string.append("only immersion");
                    // } else if (value == 3) {
                    //     result_string.append("study + immersion");
                    // } else if (value == 0) {
                    //     result_string.append("");
                    // }
                    // return result_string + ", " + dayjsDate.format("LL");
                    return dayjsDate.format("LL");
                },
            },
        ],
        [
            Legend,
            {
                tickSize: 5,
                width: 250,
                itemSelector: "#korean-legend",
                label: "터픽",
            },
        ],
        // [
        //     CalendarLabel,
        //     {
        //         key: 'korean_label',
        //         width: 40,
        //         textAlign: "middle",
        //         text: () => dayjs.weekdaysShort().map((d, i) => (i % 2 == 0 ? "" : d)),
        //     },
        // ],
    ]
);
