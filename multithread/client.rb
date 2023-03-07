# Simple web client that requests a file from the server
require 'socket'

s = TCPSocket.new 'localhost', 8989

s.write("/tmp/testfile/#{ARGV[0]}\n");

s.each_line do |line|
  puts line
end

s.close