const HOURHAND = document.querySelector("#hour");
const MINUTEHAND = document.querySelector("#minute");
const SECONDHAND = document.querySelector("#second");

var date = new Date();
    console.log(date);

    let hours = date.getHours();
    let minutes = date.getMinutes();
    let seconds = date.getSeconds();


    let hrPosition = hours*360/12 + ((minutes*360/60)/12);
    let minPosition = minutes*360/60 + ((seconds*360/60)/60);
    let secPosition = seconds*360/60;

function runTheClock() {
    
    hrPosition = hrPosition + (3/360);//for continous movement of hands of clock we have 360 degrees divided by total seconds 360/12/3600
    minPosition = minPosition + (6/60);// 360/60/60
    secPosition = secPosition + 6;//360/60

    HOURHAND.style.transform = `rotate(${hrPosition}deg)`; //" rotate(' + hrPosition + '  deg) " `rotate(${hrPosition}deg)`;
    MINUTEHAND.style.transform = `rotate(${minPosition}deg)` ;//" rotate(' + minPosition + '  deg) ";
    SECONDHAND.style.transform = `rotate(${secPosition}deg)`; //" rotate(' + secPosition + '  deg) ";
}

var run = setInterval(runTheClock,1000);