wifi.setmode(wifi.STATION)
wifi.sta.config("fontanhuset", "3131313131")
function getip ()
    print("Getting IP")
    http.get('https://httpbin.org/ip', nil, function(code, data)
        if (code < 0) then
            print("HTTP request failed")
        else
            print(code, data)
        end
    end)
end

function getfeed ()
    print("Getting feed")
    http.get('http://io.adafruit.com/api/feeds/?X-AIO-Key=33980f0292044b3392a4a38a04bb4a7d', nil,  function(code, data)
        if (code < 0) then
            print("HTTP GET request failed")
        else
            print(code, data)
        end
    end)
end

function postdata (data)
    print("Putting Data in feed", data)
    http.post('http://io.adafruit.com/api/feeds/ESP/data?X-AIO-Key=33980f0292044b3392a4a38a04bb4a7d', 'Content-Type: application/x-www-form-urlencoded\r\n', 'value='..data, function(code, data)
        if (code < 0) then
            print("Http POST request failed")
        else
            print(code, data)
        end
    end)
end
uart.on("data", "!", postdata(data))

