# Fileintegritychecker

<h2>INTRODUCTION</h2>

<h4>WHAT IS FILE INTEGRITY CHECKER?</h4>
File integrity checkers are host-based tools used to verify that the files on a host have not been tampered with. By detecting unauthorized file modifications, a file integrity checker may be able to raise the alarm when a host has been compromised.

<h4>WHY DO WE NEED FILE INTEGRITY CHECKERS?</h4>
Having a “Defense in Depth” is a critical part of any serious security architecture. The term Defense in Depth means that multiple layers of defense have been established with each layer providing a backup defense in case the layers outside it are defeated. A file integrity checker is an important part of a Defense in Depth; it serves to raise the alarm if the outer layers of defense have been penetrated. A file integrity checker does not prevent an attack, but by detecting unauthorized changes to computer’s file system, a file integrity checker may detect a successful intrusion of a host.

Malicious hackers have developed numerous techniques to hide their activity on a compromised machine. If a machine without a file integrity checker is compromised, a careful attacker’s activity on the machine may never by detected, greatly increasing the amount of damage that may be done over the course of the compromise. In the event of a compromise, a file integrity checker can help identify which files may have been damaged during the compromise, thus helping in the cleanup.


<h4>HOW DO FILE INTEGRITY CHECKERS WORK?</h4>

Generally, file integrity checkers work in two phases. The first phase consists of generating a database made up of cryptographically strong hashes for all the critical files on a host. You can think of these hashes as being a unique fingerprint for each file; it’s impossible to change the file without changing its fingerprint. The database usually also contains additional file information such as size, ownership, permissions and modification dates for each file.

In the second phase, once an initial copy of this database is built (the Initial Baseline) the same calculation is periodically recalculated for the same critical files on the host. If a file has been tampered with (let’s say by an attacker who has compromised the host), one of these characteristics will have changed. Detecting these changes will allow the tampered file to be identified, providing a warning of the system compromise. If an attacker succeeds in compromising a machine he/she will sometimes attempt to subvert any file integrity checker on the compromised machine. Some file integrity checkers take steps to protect their integrity. For example, some file integrity checkers cryptographically sign the initial baseline, and then periodically check the baseline for tampering. Some file integrity checkers will monitor the OS kernel to detect tampering with the system I/O routines (which could be used to hide changes from the integrity checker). Finally, if file is modified by an authorized person, a new hash needs to be calculated for the file and the database must be updated with the new information for the modified file (otherwise the file integrity checker will flag the modified file as having been tampered with).

<h4>COMMON FEATURES</h4>
There are several features commonly found in file integrity checkers. Some of the features are related to the ability of the checker to detect changes, and some are related to protecting the checker against being subverted by attackers.

<h4>CRYPTOGRAPHIC ONE WAY HASHES</h4>

A one-way hash is a calculation that takes some data as input and produces a unique value as output. The utility of a one-way hash lies in the uniqueness of the output value.
A good one-way hash will effectively “fingerprint” the input data; if one bit of the input data changes, the hash will generate a new, unique, output value.
Another important characteristic of one-way hashes is that the original input data cannot be derived from the output value (hence the adjective “one-way”). The terms “checksums”, “message digest” and “hashes” are sometimes used to refer to this class of algorithms, especially when the one-way characteristic is not an important feature.Key fingerprint = AF19 FA27 2F94 998D FDB5 DE3D F8B5 06E4 A169 4E46
Some hashes commonly used in file integrity checkers are:
CRC-32: Cyclic Redundancy Checks (CRC) are commonly used to detect errors in data transmission. CRC-32 requires the least amount of processing of the algorithms listed here (i.e. it’s fast), but it’s insecure and can be fooled. It should only be used in situations requiring minimal security.
HAVAL: HAVAL is a derivative of the popular MD5 algorithm. It can be configured to be more or less secure than MD5, and therefore to run faster or slower than MD5.
SHA-1 (Secure Hash Algorithm): SHA-1 is the NIST standard message digest algorithm, developed by the NSA. Both SHA-1 and MD5 are enhancements to an older algorithm called MD4 (which had a known weakness). Since the NSA has kept the development process of SHA-1 secret, there is some worry that it may still share some of MD4’s problems. However no weakness has been found in SHA-1, and the NSA is generally regarded as very good at cryptography.
SHA-1 is a bit slower than MD5.
MD5: MD5 is an enhancement to MD4. Unlike SHA-1, the design decisions leading to MD5 have been publicized ... allowing for a more thorough analysis.It was developed by the RSA Corporation, a well known cryptography vendor. MD5 has been a very popular hashing algorithm, although a theoretical weakness has been found. Due to this theoretical weakness, SHA-1 is becoming more popular.




Different hashes provide different tradeoffs between speed and cryptographic strength. A hash that is very strong (cryptographically) but runs too slowly, is just as useless as a very weak hash that runs quickly. 

<h5>FILE ATTRIBUTES</h5>
In addition to maintaining a hash to verify the contents of critical files, most file integrity checkers also keep track of the various file attributes maintained by the host operating system. In the Unix world, these attributes include:
<h5>INODE NUMBER</h5>
Inode number is a unique integer that can 998D be used to index into a data structure Key This fingerprint= AF19 FA27 2F94 FDB5 DE3D
F8B5 06E4 A169 (known 4E46 as an “inode”) that specifies many of the attributes of an active file on a file system. If a file’s inode number changes, that means the file has been deleted and a new file created using the same name as the old one. The terms “inode” and “inode number” are sometimes used interchangeably.
<h5>TYPE</h5>
Indicates whether the file is a data file, or a special file such as a named pipe or an
interface to a device (character special file, block special file ...). Special files
contain no data and take up no disk space.

<h4>AVAILABLE APPROACHES ARE</h4>

<b>Netwrix</b> is a private IT security software company, which offers IT auditing solutions for systems and applications across IT infrastructure.Netwrix Auditor for Windows File Servers delivers complete visibility into everything happening on your file servers. It provides actionable audit data about all changes made to files, folders, shares
and permissions; reports on both successful and failed access attempts; and enables file analysis reporting for improved data security and information management.
<b>CimTrak</b> is a comprehensive security, integrity and compliance application that is easy to deploy and scales to the largest of global networks. CimTrak’s automated detection process, flexible response options, and auditing capabilities make it a powerful compliance, information assurance and security tool.Protects critical files from changes, whether malicious or accidental, that can take down your critical IT infrastructure, threaten critical data, or cause non-compliance with with regulations such as PCI.Change is inevitable in the IT environment. CimTrak delivers integrity monitoring, proactive incident response, change control, and auditing capabilities in one easy to use and cost effective file integrity monitoring tool. 
<b>NNT Change Tracker</b> Enterprise provides continuous protection against known and emerging cyber security threats in an easy to use solution, offering true enterprise coverage through agent-based and agentless monitoring options. Unlike traditional scanning solutions, NNT Change Tracker uses automated file integrity monitoring to provide continuous, real-time change detection monitoring and exposure of vulnerabilities.NNT Change Tracker is widely used for compliance programs, host intrusion detection and change control for enterprise IT systems. Configuration data is tracked from any IT system, including Servers and Desktops, database systems, firewalls, network routers and switches, with a baseline stored for each device. 
<b>Verisys</b> is an advanced system and file integrity monitoring solution for Windows that allows you to maintain the integrity of business critical files and data by detecting unauthorised changes.
<b>CSP</b>'s File Integrity Checker is designed to work with our suite of security tools to provide a complete audit and monitoring solution for OSS and Guardian file systems
<b>nCircle</b> File Integrity Monitor™ provides an agentless file integrity auditing solution that gives you the ability to monitor an asset's details all the way down to the file level without requiring software agents on the monitored system. nCircle's file integrity monitoring solution discovers significant file integrity detail
<b>Milksoft</b> is used  for Each utility has been designed to keep your time and make your work more comfortable. 
<b>ReadNotify</b> will let you know when your document or PDF was opened, but will also let you know the date, time, location, ISP, etc regarding each reading, Recipient / reader details. When applicable it will give you details showing when your document was Printed out (on paper) or Saved (a copy made to disk).Details on whether or not it was forwarded (and where possible; to whom).Which pages of your PDF were read, Length of time read and How many times it was opened and re-opened (with optional instant notifications each time).
<b>Power Admin</b> File Sight will help you determine who is reading from and writing to important files. It can tell you when a new file or folder is created or renamed. And, when a file or folder gets deleted, PA File Sight can tell you who did it. Plus, you can often find out what program was used to perform the action.
<b>Tripwire</b> for Servers determines how UNIX and Microsoft Windows file systems, and Windows registry keys have changed. It begins by creating a baseline database of files, directories, and the Registry. 


<h4>System Requirements</h4>
The requirements for the file integrity checker are
<h5>Hardware</h5>
•	Pentium® II 266 MHz processor or equivalent (Pentium® III recommended)
•	128 MB RAM (256 MB RAM recommended)
•	100 MB free hard drive space (250 MB free hard drive space recommended)
•	High Color display adapter at 800x600 resolution (High Color display adapter at 1024x768 resolution recommended)
•	Dial-Up Internet Connection (Broadband Highly Recommended, Cable Modem or DSL)
<h5>SOFTWARE</h5>
Linux operating system with 32/64 bit processor , and the libraries that are needed are 
• dirent.h
• sys/stat.h
• unistd.h
• sys/types.h
• sys/mman.h
• fcntl.h
• openssl/md5.h
• time.h


<h4>System Design</h5>
ALGORITHM
Step 1 : Start<br>
Step 2 : Check a file(sign file,for identification whether the program is being run for the first time or not) if it is empty goto step3 else goto step 6<br>
Step 3 : Read the path fo the folder to be monitored from the user and write it to a file(so that it can be retrieved when program executes next time) and write something to sign file(to make to non empty) if folder exists and goto step 4 else print the message folder doesn’t exits.<br>
Step 4 : Read the new password from the user and write it to a file.<br>
Step 5 : Calculate the hash, path, last accessed time, name and inode number of each file of the given folder and stor these details in a file(Initial database) and goto step 12<br>
Step 6 : Retrieve the folder path from the file( in which folder path is stored) and calculate the hash, path, last accessed time, name and inode number of each file of the folder and store at runtime.<br>
Step 7 : For each file, based on the inode number compare the hash, path, last accessed time, name calculated at runtime with hash, path, last accessed time, name of file calculated at runtime with hash, path, last accessed time, name of file stored in the file(database) respectively. If all the properties of the each file are same then goto step 11 else goto step 8<br>
Step 8 : Read the password from the user and also read whether the file modified by the user or not(yes/no).If ‘yes’  goto step 9. If ‘no’ goto step 10<br>
Step 9 : Compare read password with password stored in the file. If both are same update file properties(hash, path, last accessed time and name) in the file(database) else goto step 12<br>
Step 10 : Compare read password with password stored in the file. If both are same alert the user about modification of the files by malicious virus or unknown user.<br>
Step 11 : Print ‘no file has got modified’<br>
Step 12 : Stop<br>
