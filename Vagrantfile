Vagrant.configure(2) do |config|
  config.vm.box = "ubuntu/trusty64"

  # Fix error stdin no tty
  #
  config.vm.provision "fix-no-tty", type: "shell" do |s|
    s.privileged = false
    s.inline = "sudo sed -i '/tty/!s/mesg n/tty -s \\&\\& mesg n/' /root/.profile"
  end

  # Setup the provisioner Chef-Solo
  #
  config.vm.provision "chef_solo" do |chef|
    chef.add_recipe "scarefault"
    chef.add_recipe "gpp"
    chef.add_recipe "java"
    chef.add_recipe "grails"
  end
end
