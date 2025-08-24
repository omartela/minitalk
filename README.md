# Minitalk

A Unix signal-based inter-process communication (IPC) project developed as part of the 42 School curriculum.

## 📖 Overview

Minitalk is a client-server communication system that transmits text messages using only Unix signals (`SIGUSR1` and `SIGUSR2`). The project demonstrates low-level system programming concepts including signal handling, bit manipulation, and process communication.

### How It Works

- **Server**: Listens for signals and reconstructs messages bit by bit
- **Client**: Converts text messages to binary and transmits them via signals
- **Protocol**: Uses `SIGUSR1` for bit '1' and `SIGUSR2` for bit '0'
- **Acknowledgment**: Server confirms receipt of each bit to ensure reliability

## 🚀 Getting Started

### Prerequisites

- GCC compiler
- Make
- Unix-like operating system (Linux, macOS)

### Installation

1. Clone the repository:
```bash
git clone https://github.com/omartela/minitalk.git
cd minitalk
```

2. Compile the project:
```bash
make
```

This will create two executables: `client` and `server`.

## 💻 Usage

### Starting the Server

```bash
./server
```

The server will start and display its Process ID (PID):
```
12345
```

### Sending Messages

In another terminal, use the client to send messages:

```bash
./client <server_pid> "<message>"
```

**Example:**
```bash
./client 12345 "Hello, World!"
```

**Output:**
- Client: `Message received`
- Server: `Hello, World!`

### More Examples

```bash
# Send a simple greeting
./client 12345 "Hello from client!"

# Send a longer message
./client 12345 "This is a test of the minitalk communication system."

# Send special characters
./client 12345 "Numbers: 123, Symbols: @#$%"
```

## 🏗️ Project Structure

```
minitalk/
├── Makefile                # Build configuration
├── README.md              # Project documentation
├── includes/
│   └── minitalk.h        # Header file with includes and definitions
└── src/
    ├── client.c          # Client implementation
    ├── server.c          # Server implementation
    └── libft/            # Custom C library
        ├── Makefile      # libft build configuration
        ├── libft.h       # libft header
        └── *.c           # libft function implementations
```

## 🔧 Technical Implementation

### Signal Protocol

The communication protocol works as follows:

1. **Bit Transmission**: Each character is sent bit by bit (8 bits per character)
2. **Signal Mapping**:
   - `SIGUSR1` = Binary '1'
   - `SIGUSR2` = Binary '0'
3. **Acknowledgment**: Server sends `SIGUSR2` after receiving each bit
4. **Message Termination**: Client sends null terminator (`\0`) to end message
5. **Completion**: Server sends `SIGUSR1` to confirm message completion

### Key Features

- **Reliable Transmission**: Acknowledgment system ensures no data loss
- **Timeout Protection**: Client detects unresponsive servers
- **Multi-client Support**: Server can handle messages from different clients
- **Error Handling**: Proper signal handling with `sigaction()`
- **Memory Management**: Clean memory allocation and deallocation

### Code Highlights

**Client - Bit Transmission:**
```c
static int char_to_bin(char c, int pid)
{
    int bit_index = 7;
    while (bit_index >= 0)
    {
        if ((c >> bit_index) & 1)
            kill(pid, SIGUSR1);  // Send '1'
        else
            kill(pid, SIGUSR2);  // Send '0'
        // Wait for acknowledgment...
        bit_index--;
    }
}
```

**Server - Bit Reception:**
```c
static void bin_to_char(int signum, char *c)
{
    if (signum == SIGUSR1)
        *c = (*c << 1) | 1;    // Received '1'
    else if (signum == SIGUSR2)
        *c = *c << 1;          // Received '0'
}
```

## 🛠️ Build Commands

```bash
# Compile everything
make

# Compile only libft
make libft

# Clean object files
make clean

# Clean everything (objects + executables)
make fclean

# Rebuild everything
make re
```

## 🧪 Testing

### Basic Test
```bash
# Terminal 1: Start server
./server

# Terminal 2: Send test message
./client <pid> "Test message"
```

### Stress Test
```bash
# Send long message
./client <pid> "This is a very long message to test the reliability of the signal-based communication system implemented in minitalk."

# Send special characters
./client <pid> "Testing: !@#$%^&*()_+{}|:<>?[];',./\`~"
```

## ❌ Troubleshooting

### Common Issues

1. **"No response from server"**
   - Ensure server is running
   - Verify correct PID
   - Check if server process exists: `ps -p <pid>`

2. **Permission denied**
   - Make sure executables have execute permissions
   - Run: `chmod +x client server`

3. **Compilation errors**
   - Ensure GCC is installed
   - Check system compatibility (Unix-like required)

### Debug Mode

The project is compiled with debug flags (`-g`). Use GDB for debugging:
```bash
gdb ./server
gdb ./client
```

## 📚 Learning Objectives

This project helps understand:

- **Unix Signals**: SIGUSR1, SIGUSR2, signal handling
- **Bit Manipulation**: Converting data to binary representation
- **Process Communication**: Inter-process communication techniques
- **System Calls**: `kill()`, `sigaction()`, `getpid()`
- **Concurrency**: Handling asynchronous signal delivery
- **Error Handling**: Robust system programming practices

## 🤝 Contributing

This is an educational project for 42 School. While contributions are welcome, please respect academic integrity policies.

## 📄 License

This project is part of the 42 School curriculum and follows their academic guidelines.

## 👨‍💻 Author

**omartela** - [GitHub Profile](https://github.com/omartela)

---

*Built with ❤️ at 42 School*
