# Test file generator
require 'securerandom'

directory = '/tmp/testfile'

# Create 50 files with random strings
50.times do |i|
  # Generate a random string
  random_string = SecureRandom.hex(16)

  # Define the file name
  file_name = "#{i+1}.txt"

  # Define the file path
  file_path = "#{directory}/#{file_name}"

  # Write the string to a file
  File.open(file_path, 'w') do |file|
    file.write(random_string)
  end

  puts "Created file #{file_path}"

end