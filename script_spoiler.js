const cal_spoiler = new CalHeatmap();
var spoiler_options = {
    itemSelector: "#cal-spoiler-heatmap",
    data: {
        source: "./records/spoiler_track.csv",
        type: "csv",
        x: "date",
        y: (d) => +d["spoiler"],
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
            scheme: "Greys",
            domain: [0, 1],
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
};

var spoiler_plugs = [
    [
        Tooltip,
        {
            text: function (date, value, dayjsDate) {
                return (
                    (value ? "oops😟" : "yay!😄") + ", " + dayjsDate.format("LL")
                );
            },
        },
    ],
    // [
    //     CalendarLabel,
    //     {
    //         key: 'spoiler_label',
    //         width: 40,
    //         textAlign: "middle",
    //         text: () => dayjs.weekdaysShort().map((d, i) => (i % 2 == 0 ? "" : d)),
    //     },
    // ],
];

cal_spoiler.paint(
    spoiler_options, spoiler_plugs
);
