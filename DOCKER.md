## Docker

A Docker image is available at https://hub.docker.com/r/lumoc/rscp2mqtt

### Configuration

Create a config file as described in the [Readme](README.md).

### Start the docker container

```
docker run -e TZ=Europe/Berlin --rm -v /path/to/your/.config:/opt/rscp2mqtt/.config lumoc/rscp2mqtt:latest
```

### Start the docker container including InfluxDB support 
 
```
docker run -e TZ=Europe/Berlin --rm -v /path/to/your/.config:/opt/rscp2mqtt/.config lumoc/rscp2mqtt:latest-with-influxdb
```
