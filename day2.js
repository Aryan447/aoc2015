const fs = require("fs");

const lines = fs.readFileSync("day2.input", "utf-8").split("\n");

let totalPaper = 0;
let totalRibbon = 0;

for (const line of lines) {
    if (!line.trim()) continue;

    const [l, w, h] = line.split("x").map(Number);

    const area = 2 * (l * w + w * h + l * h);
    const extra = Math.min(l * w, w * h, l * h);
    totalPaper += area + extra;

    const perimeter = 2 * (l + w + h - Math.max(l, w, h));
    const bow = l * w * h;
    totalRibbon += perimeter + bow;
}

console.log(totalPaper);
console.log(totalRibbon);
