import weather

def test_weather():
    data = [23.5, 25.0, 24.0, 23.5, 22.0, 25.0, 23.5]
    assert abs(weather.mean(data) - 23.92) < 0.01
    assert abs(weather.std(data) - 1.08) < 0.01
    assert abs(weather.median(data) - 23.5) < 0.01
    assert weather.mode(data) == 23.5

test_weather()
