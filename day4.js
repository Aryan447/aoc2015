const crypto = require("crypto");

const key = "yzbqklnj";

function part1(key) {
    let i = 0;

    while (true) {
        const hash = crypto
            .createHash("md5")
            .update(key + i)
            .digest("hex");

        if (hash.startsWith("00000")) {
            console.log("Part1: ", i);
            break;
        }

        i++;
    }
}

function part2(key) {
    let i = 0;

    while (true) {
        const hash = crypto
            .createHash("md5")
            .update(key + i)
            .digest("hex");

        if (hash.startsWith("000000")) {
            console.log("Part2: ", i);
            break;
        }

        i++;
    }
}


part1(key);
part2(key);
