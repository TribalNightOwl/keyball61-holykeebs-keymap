# Build
util/docker_build.sh keyball/keyball61:TribalNightOwl

# Flash

- Disconnect power
- Disconnect TRRS from one side


- Hold the reset button in the controller while connecting USB power
- The controller will show up as a mounted drive named `RPI-RP2`
- Drag the `.build/keyball_keyball61_TribalNightOwl.uf2` to the mounted drive `RPI-RP2`
- The half keyboard will be flashed and the `RPI-RP2` drive will be unmounted
- Repeat with the other keyboard half

- After both halves have been flashed:
    - disconnect USB power
    - reconnect TRRS to the other side
    - reconnect USB power