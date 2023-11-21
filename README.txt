
BUILD INSTRUCTIONS:

1. Open the AuthenticationService.sln file inside the AuthenticationService folder at root. 
2. Build the TCP project first, since it is a static library.
3. Build the other 3 projects after that. AuthenticationService_Server, AuthenticationClientServer,Chat_Client.
4. The SQL file is in the root folder under, Auth_Database. 
5. Initialize your SQL with this. 
6. After Building, copy the dll files inside the RequiredDLL at the solution directory to the build folder.\


RUN INSTRUCTIONS:
1. Open the AuthenticationService_Server.exe first. This is the server that connects to the SQL database.
2. Enter your SQL database password to connect to database.
3. Open the AuthenticationClientServer.exe second. This is the server that accepts clients to connect to it. 
4. This connects itself as a client to the AuthenticationService_Server.
5. Open the Chat_Client.exe third. This is the client where you register and authenticate.
6. In the client, you have a menu with options 1. Create Account and 2. Authenticate Account.
7. Choose the option by entering the number. 
8. Enter your email and password in the respective fields. 


VIDEO LINK : https://youtu.be/qMRi-GsRCtM
