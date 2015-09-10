#include <stdio.h>

main( int argc, char** argv)
{
	int pid = 0;

	printf( "Parent about to fork\n" );

	pid = fork();

	if ( pid < 0 ) /* error forking*/
	{
		fprintf( stderr, "Fork failed\n" );
		exit( -1 );
	}
	else if ( pid == 0 ) /* the child process will execute the branch*/
	{
		execlp( "/bin/ls", "ls",  "-lt", NULL);
	}
	else
	{
		printf( "Parent waiting for child [PID = %d] to complete\n", pid );
		wait( NULL );
		printf( "Child has completed\n" );
	}
	
	return 0;
}
