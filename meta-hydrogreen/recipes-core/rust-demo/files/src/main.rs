extern crate termios;

use termios::*;

use std::fs::File;
use std::io::Write;
use std::os::fd::AsRawFd;

const lora_device_string: &str = "/dev/ttyS0";

fn main() -> std::io::Result<()> {
    let mut lora_device_file = File::options()
        .read(true)
        .write(true)
        .create(false)
        .open(lora_device_string)?;

    let lora_device_fd = lora_device_file.as_raw_fd();

    let mut tty = Termios::from_fd(lora_device_fd)?;

    tty.c_iflag = IGNPAR | IGNBRK;
    tty.c_oflag = 0;
    tty.c_cflag = CS8 | CREAD | CLOCAL;
    tty.c_lflag = 0;

    cfsetspeed(&mut tty, B9600)?;
    tcsetattr(lora_device_fd, TCSANOW, &tty);
    tcflush(lora_device_fd, TCIOFLUSH)?;

    println!("Writing to lora device...\n");
    write!(lora_device_file, "Hello world\r");

    Ok(())
}
