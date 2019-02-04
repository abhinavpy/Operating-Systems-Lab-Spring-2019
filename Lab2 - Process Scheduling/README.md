Source `Operating Systems Concepts - Abraham Silberschatz, Peter B Galvin, Greg Gagne : Eighth Edition.`
# Process Concepts
A process is a program in execution. A process is more than the program code, which is sometimes known as the **text section**. It also includes
 the current activity, as represented by the value of the **program counter** and the contents of the processor's registers. A process 
 generally also includes the **process stack**, which contains temporary data (such as function parameters, return addresses, and local variables),
 and a **data section**, which contains global variables. A process may also include a heap, which is memory that is dynamically allocated
 during the process runtime.
 
 A program becomes a process when the executable file is loaded into the memory.
 
 Although two processes may be associated with the same program, they are nevertheless considered two separate execution sequences.
 For instance, several users may be running different copies of the main program, or the same user may invoke many copies of the Web browser
 program. Each of these is a separate process; and although the text sections are equivalent, the data heap, and stack sections vary.
 It is also common to have a process that spawns many processes as it runs. 
 
 ## Process States
 As a process executes, it changes state. The state of the process is defined by the current activity of the process.
 * **New**. The process being created.
 * **Running**. Instructions are being executed.
 * **Waiting**. The process is waiting for some event to occur (such as an I/O completion or reception of a signal).
 * **Ready**. The process is waiting to be assigned to a processor.
 * **Terminated**. The process has finished execution.
 It is important to realize that only one process can be running on any processor at any instant. Many processors may be ready and 
 waiting, however. 
 
 
 ## Process Control Block
 Each process is represented in the operating system by a **process control block (PCB)** - also called a *task control block*. It 
 contains many pieces of information associated with a specific process, including these:
 * **Process State** - The state may be new, ready, running, waiting, halted and so on.
 * **Program Counter** - The counter indicates the address of the next instruction to be executed for this process.
 * **CPU Registers** - The registers vary in number and type, depending on the stack pointers, and general-purpose registers, plus any condition-code information.
 Along with the program counter, this state information must be saved when an interrupt occurs, to allow the process to be 
 continued correctly afterward.
 * **Memory-Management Information** - This information may include such information as the value of the base and the limit registers,
 the page tables or the segment tables, depending on the memory system used by the operating system.
 * **Accounting Information** - This information includes the amount of CPU and real time used, time limits, account numbers, job or process numbers and so on.
 * **I/O status information** - This information includes the list of I/O devices allocated to the process, a list of open files, and so on.
 
 # Process Scheduling
 The CPU scheduler selects an available process (possibly from a set of several available processes) for program execution.
 ## Scheduling Queues
 As processes enter the system, they are put into a job queue, which consists of all processes in the system. The processes that are
 residing in main memory and are ready and waiting to execute are kept on a list called the ready queue. 
 
 This queue is generally stored as a linked list, A ready queue header contains pointers to the first and final PCBs in the list. Each
 PCB includes a pointer field that points to the next PCB in the ready queue.
 The system also includes other queues. When a process is allocated the CPU, it executes for a while and eventually quits, is interrupted
  or waits for the occurence of a particular event, such as the completion of an I/O request. Suppose the process makes an I/O request to 
  a shared device, such as a disk. Since there are many processes in the system, the disk may be busy with the I/O request of some other 
  process. The process therefore may have to wait for the disk. The list of processes waiting for a particular I/O device is called a device queue.
  
  

 
 
