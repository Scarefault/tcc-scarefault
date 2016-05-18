#include "SpreaderData.hpp"

namespace Helper
{
  ADDRESS address_spreader;

  SpreaderData::SpreaderData()
  {
    address_spreader = this;
  }

  void SpreaderData::write_data()
  {
    std::fstream test_stream;

    test_stream.open( TESTFILE, WRITE|APPEND );

    if( test_stream.is_open() )
    {
      write_header( &test_stream );
      analizer_methods( &test_stream );
      conclude_data( &test_stream );

      test_stream.close();
    } else
    {
      std::cout << "Unable to open TESTFILE..." << std::endl;
    }
  }

  void SpreaderData::write_header( std::fstream * test_stream )
  {
    (* test_stream) << "package " << data_ptr->package_name << std::endl
      << std::endl
      << "import org.junit.*" << std::endl
      << "import grails.test.mixin.*" << std::endl
      << std::endl
      << "@TestFor(" << data_ptr->class_name << ")" << std::endl
      << "class " << data_ptr->class_name << "Tests {" << std::endl
      << std::endl;
  }

  void SpreaderData::analizer_methods( std::fstream * test_stream )
  {
    if( (* test_stream).is_open() )
    {
      const int qtd_methods = data_ptr->methods.size();

      for( int i = 0; i < qtd_methods; i++ )
      {
        if( data_ptr->methods[ i ].name == "create" )
        {
          write_test_create( test_stream );
        } else if( data_ptr->methods[ i ].name == "show" )
        {
          write_test_show( test_stream );
        } else if( data_ptr->methods[ i ].name == "delete" )
        {
          write_test_delete( test_stream );
        } else if( data_ptr->methods[ i ].name == "list" )
        {
          write_test_list( test_stream );
        } else if( data_ptr->methods[ i ].name == "save" )
        {
          write_test_save( test_stream );
        }
      }
    } else
    {
      std::cout << "Unable to open TESTFILE..." << std::endl;
    }
  }

  void SpreaderData::write_test_create( std::fstream * test_stream )
  {
    (* test_stream) << "\tvoid testCreate() {" << std::endl
      << "\t\tdef model = controller.create()" << std::endl
      << "\t\tassert model.userInstance != null" << std::endl
      << "\t}" << std::endl
      << std::endl;
  }

  void SpreaderData::write_test_show( std::fstream * test_stream )
  {
    (* test_stream ) << "\tvoid testShow() {" << std::endl
      << "\t\tcontroller show" << std::endl
      << "\t\tassert flash.message != null" << std::endl
      << "\t\tassert response.redirectedUrl == '/user/list'" << std::endl
      << std::endl
      << "\t\tpopulateValidParams(params)" << std::endl
      << "\t\tdef user = new User(params)" << std::endl
      << std::endl
      << "\t\tassert user.save() != null" << std::endl
      << std::endl
      << "\t\tparams.id = user.id" << std::endl
      << std::endl
      << "\t\tdef model = controller.show()" << std::endl
      << std::endl
      << "\t\tassert model.userInstance == user" << std::endl
      << "\t}" << std::endl
      << std::endl;
  }

  void SpreaderData::write_test_delete( std::fstream * test_stream )
  {
    (* test_stream ) << "\tvoid testDelete() {" << std::endl
      << "\t\tcontroller.delete()" << std::endl
      << "\t\tassert flash.message != null" << std::endl
      << "\t\tassert response.redirectedUrl == '/user/list'" << std::endl
      << std::endl
      << "\t\tresponse.reset()" << std::endl
      << std::endl
      << "\t\tpopulateValidParams(params)" << std::endl
      << "\t\tdef user = new User(params)" << std::endl
      << std::endl
      << "\t\tassert user.save() != null" << std::endl
      << "\t\tassert User.count() == 1" << std::endl
      << std::endl
      << "\t\tparams.id = user.id" << std::endl
      << std::endl
      << "\t\tcontroller.delete()" << std::endl
      << std::endl
      << "\t\tassert User.count() == 0" << std::endl
      << "\t\tassert User.get(user.id) == null" << std::endl
      << "\t\tassert response.redirectedUrl == '/user/list'" << std::endl
      << "\t}" << std::endl
      << std::endl;
  }

  void SpreaderData::write_test_list( std::fstream * test_stream )
  {
    (* test_stream ) << "\tvoid testList() {" << std::endl
      << "\t\tdef model = controller.list()" << std::endl
      << std::endl
      << "\t\tassert model.userInstanceList.size() == 0" << std::endl
      << "\t\tassert model.userInstanceTotal == 0" << std::endl
      << "\t}" << std::endl
      << std::endl;
  }

  void SpreaderData::write_test_save( std::fstream * test_stream )
  {
    (* test_stream ) << "\tvoid testSave() {" << std::endl
      << "\t\tcontroller.save()" << std::endl
      << std::endl
      << "\t\tassert model.userInstance != null" << std::endl
      << "\t\tassert view == '/user/create'" << std::endl
      << std::endl
      << "\t\tresponse.reset()" << std::endl
      << "" << std::endl
      << "\t\tpopulateValidParams(params)" << std::endl
      << "\t\tcontroller.save()" << std::endl
      << std::endl
      << "\t\tassert response.redirectedUrl == '/user/show/1'" << std::endl
      << "\t\tassert controller.flash.message != null" << std::endl
      << "\t\tassert User.count() == 1" << std::endl
      << "\t}" << std::endl
      << std::endl;
  }

  void SpreaderData::conclude_data( std::fstream * test_stream )
  {
    (* test_stream ) << "}" << std::endl;
  }

  void SpreaderData::set_data( Helper::Data * ptr )
  {
      this->data_ptr = ptr;
  }
}
