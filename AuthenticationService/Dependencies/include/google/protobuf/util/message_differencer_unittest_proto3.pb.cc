// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/protobuf/util/message_differencer_unittest_proto3.proto
// Protobuf C++ Version: 4.26.0-dev

#include "google/protobuf/util/message_differencer_unittest_proto3.pb.h"

#include <algorithm>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
#include "google/protobuf/generated_message_tctable_impl.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
namespace proto3_unittest {

inline constexpr TestNoPresenceField::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : _cached_size_{0},
        no_presence_repeated_nested_{},
        no_presence_string_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        no_presence_nested_{nullptr},
        no_presence_bool_{false},
        no_presence_bool2_{false},
        no_presence_bool3_{false} {}

template <typename>
PROTOBUF_CONSTEXPR TestNoPresenceField::TestNoPresenceField(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct TestNoPresenceFieldDefaultTypeInternal {
  PROTOBUF_CONSTEXPR TestNoPresenceFieldDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~TestNoPresenceFieldDefaultTypeInternal() {}
  union {
    TestNoPresenceField _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 TestNoPresenceFieldDefaultTypeInternal _TestNoPresenceField_default_instance_;
}  // namespace proto3_unittest
static ::_pb::Metadata file_level_metadata_google_2fprotobuf_2futil_2fmessage_5fdifferencer_5funittest_5fproto3_2eproto[1];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_google_2fprotobuf_2futil_2fmessage_5fdifferencer_5funittest_5fproto3_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_google_2fprotobuf_2futil_2fmessage_5fdifferencer_5funittest_5fproto3_2eproto = nullptr;
const ::uint32_t
    TableStruct_google_2fprotobuf_2futil_2fmessage_5fdifferencer_5funittest_5fproto3_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        PROTOBUF_FIELD_OFFSET(::proto3_unittest::TestNoPresenceField, _impl_._has_bits_),
        PROTOBUF_FIELD_OFFSET(::proto3_unittest::TestNoPresenceField, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::proto3_unittest::TestNoPresenceField, _impl_.no_presence_bool_),
        PROTOBUF_FIELD_OFFSET(::proto3_unittest::TestNoPresenceField, _impl_.no_presence_nested_),
        PROTOBUF_FIELD_OFFSET(::proto3_unittest::TestNoPresenceField, _impl_.no_presence_repeated_nested_),
        PROTOBUF_FIELD_OFFSET(::proto3_unittest::TestNoPresenceField, _impl_.no_presence_string_),
        PROTOBUF_FIELD_OFFSET(::proto3_unittest::TestNoPresenceField, _impl_.no_presence_bool2_),
        PROTOBUF_FIELD_OFFSET(::proto3_unittest::TestNoPresenceField, _impl_.no_presence_bool3_),
        ~0u,
        0,
        ~0u,
        ~0u,
        ~0u,
        ~0u,
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, 14, -1, sizeof(::proto3_unittest::TestNoPresenceField)},
};

static const ::_pb::Message* const file_default_instances[] = {
    &::proto3_unittest::_TestNoPresenceField_default_instance_._instance,
};
const char descriptor_table_protodef_google_2fprotobuf_2futil_2fmessage_5fdifferencer_5funittest_5fproto3_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n>google/protobuf/util/message_differenc"
    "er_unittest_proto3.proto\022\017proto3_unittes"
    "t\"\216\002\n\023TestNoPresenceField\022\030\n\020no_presence"
    "_bool\030\001 \001(\010\022@\n\022no_presence_nested\030\002 \001(\0132"
    "$.proto3_unittest.TestNoPresenceField\022I\n"
    "\033no_presence_repeated_nested\030\003 \003(\0132$.pro"
    "to3_unittest.TestNoPresenceField\022\032\n\022no_p"
    "resence_string\030\004 \001(\t\022\031\n\021no_presence_bool"
    "2\030\005 \001(\010\022\031\n\021no_presence_bool3\030\006 \001(\010B\002H\001b\006"
    "proto3"
};
static ::absl::once_flag descriptor_table_google_2fprotobuf_2futil_2fmessage_5fdifferencer_5funittest_5fproto3_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_google_2fprotobuf_2futil_2fmessage_5fdifferencer_5funittest_5fproto3_2eproto = {
    false,
    false,
    366,
    descriptor_table_protodef_google_2fprotobuf_2futil_2fmessage_5fdifferencer_5funittest_5fproto3_2eproto,
    "google/protobuf/util/message_differencer_unittest_proto3.proto",
    &descriptor_table_google_2fprotobuf_2futil_2fmessage_5fdifferencer_5funittest_5fproto3_2eproto_once,
    nullptr,
    0,
    1,
    schemas,
    file_default_instances,
    TableStruct_google_2fprotobuf_2futil_2fmessage_5fdifferencer_5funittest_5fproto3_2eproto::offsets,
    file_level_metadata_google_2fprotobuf_2futil_2fmessage_5fdifferencer_5funittest_5fproto3_2eproto,
    file_level_enum_descriptors_google_2fprotobuf_2futil_2fmessage_5fdifferencer_5funittest_5fproto3_2eproto,
    file_level_service_descriptors_google_2fprotobuf_2futil_2fmessage_5fdifferencer_5funittest_5fproto3_2eproto,
};

// This function exists to be marked as weak.
// It can significantly speed up compilation by breaking up LLVM's SCC
// in the .pb.cc translation units. Large translation units see a
// reduction of more than 35% of walltime for optimized builds. Without
// the weak attribute all the messages in the file, including all the
// vtables and everything they use become part of the same SCC through
// a cycle like:
// GetMetadata -> descriptor table -> default instances ->
//   vtables -> GetMetadata
// By adding a weak function here we break the connection from the
// individual vtables back into the descriptor table.
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_google_2fprotobuf_2futil_2fmessage_5fdifferencer_5funittest_5fproto3_2eproto_getter() {
  return &descriptor_table_google_2fprotobuf_2futil_2fmessage_5fdifferencer_5funittest_5fproto3_2eproto;
}
// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_google_2fprotobuf_2futil_2fmessage_5fdifferencer_5funittest_5fproto3_2eproto(&descriptor_table_google_2fprotobuf_2futil_2fmessage_5fdifferencer_5funittest_5fproto3_2eproto);
namespace proto3_unittest {
// ===================================================================

class TestNoPresenceField::_Internal {
 public:
  using HasBits = decltype(std::declval<TestNoPresenceField>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
    8 * PROTOBUF_FIELD_OFFSET(TestNoPresenceField, _impl_._has_bits_);
};

TestNoPresenceField::TestNoPresenceField(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:proto3_unittest.TestNoPresenceField)
}
inline PROTOBUF_NDEBUG_INLINE TestNoPresenceField::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : _has_bits_{from._has_bits_},
        _cached_size_{0},
        no_presence_repeated_nested_{visibility, arena, from.no_presence_repeated_nested_},
        no_presence_string_(arena, from.no_presence_string_) {}

TestNoPresenceField::TestNoPresenceField(
    ::google::protobuf::Arena* arena,
    const TestNoPresenceField& from)
    : ::google::protobuf::Message(arena) {
  TestNoPresenceField* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);
  ::uint32_t cached_has_bits = _impl_._has_bits_[0];
  _impl_.no_presence_nested_ = (cached_has_bits & 0x00000001u) ? ::google::protobuf::Message::CopyConstruct<::proto3_unittest::TestNoPresenceField>(
                              arena, *from._impl_.no_presence_nested_)
                        : nullptr;
  ::memcpy(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, no_presence_bool_),
           reinterpret_cast<const char *>(&from._impl_) +
               offsetof(Impl_, no_presence_bool_),
           offsetof(Impl_, no_presence_bool3_) -
               offsetof(Impl_, no_presence_bool_) +
               sizeof(Impl_::no_presence_bool3_));

  // @@protoc_insertion_point(copy_constructor:proto3_unittest.TestNoPresenceField)
}
inline PROTOBUF_NDEBUG_INLINE TestNoPresenceField::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0},
        no_presence_repeated_nested_{visibility, arena},
        no_presence_string_(arena) {}

inline void TestNoPresenceField::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  ::memset(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, no_presence_nested_),
           0,
           offsetof(Impl_, no_presence_bool3_) -
               offsetof(Impl_, no_presence_nested_) +
               sizeof(Impl_::no_presence_bool3_));
}
TestNoPresenceField::~TestNoPresenceField() {
  // @@protoc_insertion_point(destructor:proto3_unittest.TestNoPresenceField)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void TestNoPresenceField::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.no_presence_string_.Destroy();
  delete _impl_.no_presence_nested_;
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
TestNoPresenceField::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::ClassData
      _data_ = {
          TestNoPresenceField::MergeImpl,
           nullptr,  // OnDemandRegisterArenaDtor
           &::google::protobuf::Message::kDescriptorMethods,
              PROTOBUF_FIELD_OFFSET(TestNoPresenceField, _impl_._cached_size_),
      };
  return &_data_;
}
PROTOBUF_NOINLINE void TestNoPresenceField::Clear() {
// @@protoc_insertion_point(message_clear_start:proto3_unittest.TestNoPresenceField)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.no_presence_repeated_nested_.Clear();
  _impl_.no_presence_string_.ClearToEmpty();
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    ABSL_DCHECK(_impl_.no_presence_nested_ != nullptr);
    _impl_.no_presence_nested_->Clear();
  }
  ::memset(&_impl_.no_presence_bool_, 0, static_cast<::size_t>(
      reinterpret_cast<char*>(&_impl_.no_presence_bool3_) -
      reinterpret_cast<char*>(&_impl_.no_presence_bool_)) + sizeof(_impl_.no_presence_bool3_));
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* TestNoPresenceField::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<3, 6, 2, 62, 2> TestNoPresenceField::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(TestNoPresenceField, _impl_._has_bits_),
    0, // no _extensions_
    6, 56,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967232,  // skipmap
    offsetof(decltype(_table_), field_entries),
    6,  // num_field_entries
    2,  // num_aux_entries
    offsetof(decltype(_table_), aux_entries),
    &_TestNoPresenceField_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::proto3_unittest::TestNoPresenceField>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    {::_pbi::TcParser::MiniParse, {}},
    // bool no_presence_bool = 1;
    {::_pbi::TcParser::SingularVarintNoZag1<bool, offsetof(TestNoPresenceField, _impl_.no_presence_bool_), 63>(),
     {8, 63, 0, PROTOBUF_FIELD_OFFSET(TestNoPresenceField, _impl_.no_presence_bool_)}},
    // .proto3_unittest.TestNoPresenceField no_presence_nested = 2;
    {::_pbi::TcParser::FastMtS1,
     {18, 0, 0, PROTOBUF_FIELD_OFFSET(TestNoPresenceField, _impl_.no_presence_nested_)}},
    // repeated .proto3_unittest.TestNoPresenceField no_presence_repeated_nested = 3;
    {::_pbi::TcParser::FastMtR1,
     {26, 63, 1, PROTOBUF_FIELD_OFFSET(TestNoPresenceField, _impl_.no_presence_repeated_nested_)}},
    // string no_presence_string = 4;
    {::_pbi::TcParser::FastUS1,
     {34, 63, 0, PROTOBUF_FIELD_OFFSET(TestNoPresenceField, _impl_.no_presence_string_)}},
    // bool no_presence_bool2 = 5;
    {::_pbi::TcParser::SingularVarintNoZag1<bool, offsetof(TestNoPresenceField, _impl_.no_presence_bool2_), 63>(),
     {40, 63, 0, PROTOBUF_FIELD_OFFSET(TestNoPresenceField, _impl_.no_presence_bool2_)}},
    // bool no_presence_bool3 = 6;
    {::_pbi::TcParser::SingularVarintNoZag1<bool, offsetof(TestNoPresenceField, _impl_.no_presence_bool3_), 63>(),
     {48, 63, 0, PROTOBUF_FIELD_OFFSET(TestNoPresenceField, _impl_.no_presence_bool3_)}},
    {::_pbi::TcParser::MiniParse, {}},
  }}, {{
    65535, 65535
  }}, {{
    // bool no_presence_bool = 1;
    {PROTOBUF_FIELD_OFFSET(TestNoPresenceField, _impl_.no_presence_bool_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kBool)},
    // .proto3_unittest.TestNoPresenceField no_presence_nested = 2;
    {PROTOBUF_FIELD_OFFSET(TestNoPresenceField, _impl_.no_presence_nested_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kMessage | ::_fl::kTvTable)},
    // repeated .proto3_unittest.TestNoPresenceField no_presence_repeated_nested = 3;
    {PROTOBUF_FIELD_OFFSET(TestNoPresenceField, _impl_.no_presence_repeated_nested_), -1, 1,
    (0 | ::_fl::kFcRepeated | ::_fl::kMessage | ::_fl::kTvTable)},
    // string no_presence_string = 4;
    {PROTOBUF_FIELD_OFFSET(TestNoPresenceField, _impl_.no_presence_string_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // bool no_presence_bool2 = 5;
    {PROTOBUF_FIELD_OFFSET(TestNoPresenceField, _impl_.no_presence_bool2_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kBool)},
    // bool no_presence_bool3 = 6;
    {PROTOBUF_FIELD_OFFSET(TestNoPresenceField, _impl_.no_presence_bool3_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kBool)},
  }}, {{
    {::_pbi::TcParser::GetTable<::proto3_unittest::TestNoPresenceField>()},
    {::_pbi::TcParser::GetTable<::proto3_unittest::TestNoPresenceField>()},
  }}, {{
    "\43\0\0\0\22\0\0\0"
    "proto3_unittest.TestNoPresenceField"
    "no_presence_string"
  }},
};

::uint8_t* TestNoPresenceField::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:proto3_unittest.TestNoPresenceField)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // bool no_presence_bool = 1;
  if (this->_internal_no_presence_bool() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteBoolToArray(
        1, this->_internal_no_presence_bool(), target);
  }

  cached_has_bits = _impl_._has_bits_[0];
  // .proto3_unittest.TestNoPresenceField no_presence_nested = 2;
  if (cached_has_bits & 0x00000001u) {
    target = ::google::protobuf::internal::WireFormatLite::InternalWriteMessage(
        2, *_impl_.no_presence_nested_, _impl_.no_presence_nested_->GetCachedSize(), target, stream);
  }

  // repeated .proto3_unittest.TestNoPresenceField no_presence_repeated_nested = 3;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_no_presence_repeated_nested_size()); i < n; i++) {
    const auto& repfield = this->_internal_no_presence_repeated_nested().Get(i);
    target = ::google::protobuf::internal::WireFormatLite::
        InternalWriteMessage(3, repfield, repfield.GetCachedSize(), target, stream);
  }

  // string no_presence_string = 4;
  if (!this->_internal_no_presence_string().empty()) {
    const std::string& _s = this->_internal_no_presence_string();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "proto3_unittest.TestNoPresenceField.no_presence_string");
    target = stream->WriteStringMaybeAliased(4, _s, target);
  }

  // bool no_presence_bool2 = 5;
  if (this->_internal_no_presence_bool2() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteBoolToArray(
        5, this->_internal_no_presence_bool2(), target);
  }

  // bool no_presence_bool3 = 6;
  if (this->_internal_no_presence_bool3() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteBoolToArray(
        6, this->_internal_no_presence_bool3(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:proto3_unittest.TestNoPresenceField)
  return target;
}

::size_t TestNoPresenceField::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:proto3_unittest.TestNoPresenceField)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .proto3_unittest.TestNoPresenceField no_presence_repeated_nested = 3;
  total_size += 1UL * this->_internal_no_presence_repeated_nested_size();
  for (const auto& msg : this->_internal_no_presence_repeated_nested()) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSize(msg);
  }
  // string no_presence_string = 4;
  if (!this->_internal_no_presence_string().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_no_presence_string());
  }

  // .proto3_unittest.TestNoPresenceField no_presence_nested = 2;
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size +=
        1 + ::google::protobuf::internal::WireFormatLite::MessageSize(*_impl_.no_presence_nested_);
  }

  // bool no_presence_bool = 1;
  if (this->_internal_no_presence_bool() != 0) {
    total_size += 2;
  }

  // bool no_presence_bool2 = 5;
  if (this->_internal_no_presence_bool2() != 0) {
    total_size += 2;
  }

  // bool no_presence_bool3 = 6;
  if (this->_internal_no_presence_bool3() != 0) {
    total_size += 2;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void TestNoPresenceField::MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg) {
  auto* const _this = static_cast<TestNoPresenceField*>(&to_msg);
  auto& from = static_cast<const TestNoPresenceField&>(from_msg);
  ::google::protobuf::Arena* arena = _this->GetArena();
  // @@protoc_insertion_point(class_specific_merge_from_start:proto3_unittest.TestNoPresenceField)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_internal_mutable_no_presence_repeated_nested()->MergeFrom(
      from._internal_no_presence_repeated_nested());
  if (!from._internal_no_presence_string().empty()) {
    _this->_internal_set_no_presence_string(from._internal_no_presence_string());
  }
  cached_has_bits = from._impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    ABSL_DCHECK(from._impl_.no_presence_nested_ != nullptr);
    if (_this->_impl_.no_presence_nested_ == nullptr) {
      _this->_impl_.no_presence_nested_ =
          ::google::protobuf::Message::CopyConstruct<::proto3_unittest::TestNoPresenceField>(arena, *from._impl_.no_presence_nested_);
    } else {
      _this->_impl_.no_presence_nested_->MergeFrom(*from._impl_.no_presence_nested_);
    }
  }
  if (from._internal_no_presence_bool() != 0) {
    _this->_internal_set_no_presence_bool(from._internal_no_presence_bool());
  }
  if (from._internal_no_presence_bool2() != 0) {
    _this->_internal_set_no_presence_bool2(from._internal_no_presence_bool2());
  }
  if (from._internal_no_presence_bool3() != 0) {
    _this->_internal_set_no_presence_bool3(from._internal_no_presence_bool3());
  }
  _this->_impl_._has_bits_[0] |= cached_has_bits;
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void TestNoPresenceField::CopyFrom(const TestNoPresenceField& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:proto3_unittest.TestNoPresenceField)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool TestNoPresenceField::IsInitialized() const {
  return true;
}

void TestNoPresenceField::InternalSwap(TestNoPresenceField* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  _impl_.no_presence_repeated_nested_.InternalSwap(&other->_impl_.no_presence_repeated_nested_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.no_presence_string_, &other->_impl_.no_presence_string_, arena);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(TestNoPresenceField, _impl_.no_presence_bool3_)
      + sizeof(TestNoPresenceField::_impl_.no_presence_bool3_)
      - PROTOBUF_FIELD_OFFSET(TestNoPresenceField, _impl_.no_presence_nested_)>(
          reinterpret_cast<char*>(&_impl_.no_presence_nested_),
          reinterpret_cast<char*>(&other->_impl_.no_presence_nested_));
}

::google::protobuf::Metadata TestNoPresenceField::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_google_2fprotobuf_2futil_2fmessage_5fdifferencer_5funittest_5fproto3_2eproto_getter, &descriptor_table_google_2fprotobuf_2futil_2fmessage_5fdifferencer_5funittest_5fproto3_2eproto_once,
      file_level_metadata_google_2fprotobuf_2futil_2fmessage_5fdifferencer_5funittest_5fproto3_2eproto[0]);
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace proto3_unittest
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
#include "google/protobuf/port_undef.inc"
