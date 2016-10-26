wifi.setmode(wifi.STATION)
wifi.sta.config("fontanhuset", "3131313131")
uart.on("data", "!",
    function(data)
        print("Här skall jag (serializera) data?:", data)
        print("och skicka detta till en webserver via en POST req?")
    end
)
