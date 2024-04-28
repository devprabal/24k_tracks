function getIntBeforeDecimalPoint(number) {
    const numberString = number.toString();
  if (!numberString.includes(".")) {
    return number;
  }
  const parts = numberString.split(".");
  const integer = parseInt(parts[0], 10);
  return integer;
}

function getDecimalDigits(number) {
    const numberString = number.toString();

    if (!numberString.includes(".")) {
        return [];
    }
    const parts = numberString.split(".");
    const decimalString = parts[1];
    const digits = decimalString.split("").map(Number);

    return digits;
}

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
                    if(value) {
                        var int_before_decimal_pt = getIntBeforeDecimalPoint(value);
                        var digits_after_decimal_pt = getDecimalDigits(value);
                        if(digits_after_decimal_pt.length === 0) {
                            // console.log("no digits for " + value);
                            var tooltip_string = "" + int_before_decimal_pt + "/5 " + "on " + dayjsDate.format("LL");
                            return tooltip_string;
                        }
                        else {
                            // console.log(digits_after_decimal_pt);
                            var tooltip_string = "" + int_before_decimal_pt + "/5 " + "on " + dayjsDate.format("LL") + "\n *";
                            for (var i = 0; i < digits_after_decimal_pt.length; i++) {
                                if(digits_after_decimal_pt[i] === 1 && i === 0) {
                                    tooltip_string += "Weights ";
                                }
                                if(digits_after_decimal_pt[i] === 1 && i === 1) {
                                    tooltip_string += "Cardio ";
                                }
                                if(digits_after_decimal_pt[i] === 1 && i === 2) {
                                    tooltip_string += "HIIT ";
                                }
                                if(digits_after_decimal_pt[i] === 1 && i === 3) {
                                    tooltip_string += "Spinning ";
                                }
                                if(digits_after_decimal_pt[i] === 1 && i === 4) {
                                    tooltip_string += "BodyWtExAtHome ";
                                }
                            }
                            return tooltip_string;
                        }
                    } else {
                        return "No data on " + dayjsDate.format("LL");
                    }
                },
            },
        ],
    ]
);
