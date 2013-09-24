class MyMonitor
{
    int counter = 0;

    //init
    public MyMonitor( int init )
    {
        counter = init;
    }

    //Signal
    public synchronized void S()
    {
        counter++;
        notify();
    }

    //Wait
    public synchronized void W()
    {
        if( counter == 0 )
        {
            try
            {
                wait();
            }
            catch(InterruptedException e) { }
        }

        counter--;
    }
}
