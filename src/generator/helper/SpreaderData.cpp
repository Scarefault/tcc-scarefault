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
      std::cout << "domain_base: " << data_ptr->domain_base << std::endl;
      std::cout << "category_MVC: " << data_ptr->category_MVC << std::endl;

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
        } else if( data_ptr->methods[ i ].name == "edit" )
        {
          write_test_edit( test_stream );
        } else if( data_ptr->methods[ i ].name == "update" )
        {
          write_test_update( test_stream );
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
      << std::endl
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

  void SpreaderData::write_test_edit( std::fstream * test_stream )
  {
    (* test_stream ) << "\tvoid testEdit() {" << std::endl
      << "\t\tcontroller.edit()" << std::endl
      << std::endl
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
      << "\t\tdef model = controller.edit()" << std::endl
      << std::endl
      << "\t\tassert model.userInstance == user" << std::endl
      << "\t}" << std::endl
      << std::endl;
  }

  void SpreaderData::write_test_update( std::fstream * test_stream )
  {
    (* test_stream ) << "\tvoid testUpdate() {" << std::endl
      << "\t\tcontroller.update()" << std::endl
      << std::endl
      << "\t\tassert flash.message != null" << std::endl
      << "\t\tassert response.redirectedUrl == '/user/list'" << std::endl
      << std::endl
      << "\t\tresponse.reset()" << std::endl
      << std::endl
      << "\t\tpopulateValidParams(params)" << std::endl
      << "\t\tdef user = new User(params)" << std::endl
      << std::endl
      << "\t\tassert user.save() != null" << std::endl
      << std::endl
      << "\t\t// test invalid parameters in update" << std::endl
      << "\t\tparams.id = user.id" << std::endl
      << "\t\t//TODO: add invalid values to params object" << std::endl
      << std::endl
      << "\t\tcontroller.update()" << std::endl
      << std::endl
      << "\t\tassert view == \"/user/edit\"" << std::endl
      << "\t\tassert model.userInstance != null" << std::endl
      << std::endl
      << "\t\tuser.clearErrors()" << std::endl
      << std::endl
      << "\t\tpopulateValidParams(params)" << std::endl
      << "\t\tcontroller.update()" << std::endl
      << std::endl
      << "\t\tassert response.redirectedUrl == \"/user/show/$user.id\"" << std::endl
      << "\t\tassert flash.message != null" << std::endl
      << std::endl
      << "\t\tresponse.reset()" << std::endl
      << "\t\tuser.clearErrors()" << std::endl
      << std::endl
      << "\t\tpopulateValidParams(params)" << std::endl
      << "\t\tparams.id = user.id" << std::endl
      << "\t\tparams.version = -1" << std::endl
      << "\t\tcontroller.update()" << std::endl
      << std::endl
      << "\t\tassert view == \"/user/edit\"" << std::endl
      << "\t\tassert model.userInstance != null" << std::endl
      << "\t\tassert model.userInstance.errors.getFieldError('version')" << std::endl
      << "\t\tassert flash.message != null" << std::endl
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
