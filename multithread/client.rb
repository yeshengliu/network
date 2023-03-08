# Simple web client that requests a file from the server
require 'socket'
start_time = Process.clock_gettime(Process::CLOCK_MONOTONIC)

s = TCPSocket.new 'localhost', 8989

s.write("/tmp/testfile/#{ARGV[0]}\n");

s.each_line do |line|
  puts line
end

s.close
endtime = Process.clock_gettime(Process::CLOCK_MONOTONIC)
puts "Time elapsed: #{(endtime - start_time)*1000} ms (#{ARGV[0]})"