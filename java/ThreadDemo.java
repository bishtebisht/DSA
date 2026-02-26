//THREADS IN JAVA
//A thread is a lightweight process that can run concurrently with other threads within the same program.
//EG: A web browser can have multiple threads for handling user interface, loading web pages, and running background tasks simultaneously.

//Creating a Thread by Extending the Thread Class
//To create a thread by extending the Thread class, you need to follow these steps:
//1. Create a new class that extends the Thread class.
//2. Override the run() method to define the code that will be executed when the thread is started.
//3. Create an instance of the thread class and call the start() method to begin execution of the thread.

class MyThread extends Thread {
    // Override the run() method to define the thread's behavior
    public void run() {
        // Code to be executed in the thread
        System.out.println("Thread is running: " + Thread.currentThread().getName());
    }
}

public class ThreadDemo {
    public static void main(String[] args) {
        
    }

    
}
