// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/protobuf/unittest_invalid_features.proto
// Protobuf C++ Version: 4.26.0-dev

#ifndef GOOGLE_PROTOBUF_INCLUDED_google_2fprotobuf_2funittest_5finvalid_5ffeatures_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_google_2fprotobuf_2funittest_5finvalid_5ffeatures_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION < 4025000
#error "This file was generated by a newer version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please update"
#error "your headers."
#endif  // PROTOBUF_VERSION

#if 4025000 < PROTOBUF_MIN_PROTOC_VERSION
#error "This file was generated by an older version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please"
#error "regenerate this file with a newer version of protoc."
#endif  // PROTOBUF_MIN_PROTOC_VERSION
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
#include "google/protobuf/descriptor.pb.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_google_2fprotobuf_2funittest_5finvalid_5ffeatures_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_google_2fprotobuf_2funittest_5finvalid_5ffeatures_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_google_2fprotobuf_2funittest_5finvalid_5ffeatures_2eproto;
namespace pb {
class TestInvalidFeatures;
struct TestInvalidFeaturesDefaultTypeInternal;
extern TestInvalidFeaturesDefaultTypeInternal _TestInvalidFeatures_default_instance_;
}  // namespace pb
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace pb {

// ===================================================================


// -------------------------------------------------------------------

class TestInvalidFeatures final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:pb.TestInvalidFeatures) */ {
 public:
  inline TestInvalidFeatures() : TestInvalidFeatures(nullptr) {}
  ~TestInvalidFeatures() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR TestInvalidFeatures(
      ::google::protobuf::internal::ConstantInitialized);

  inline TestInvalidFeatures(const TestInvalidFeatures& from) : TestInvalidFeatures(nullptr, from) {}
  TestInvalidFeatures(TestInvalidFeatures&& from) noexcept : TestInvalidFeatures() {
    *this = ::std::move(from);
  }

  inline TestInvalidFeatures& operator=(const TestInvalidFeatures& from) {
    CopyFrom(from);
    return *this;
  }
  inline TestInvalidFeatures& operator=(TestInvalidFeatures&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const TestInvalidFeatures& default_instance() {
    return *internal_default_instance();
  }
  static inline const TestInvalidFeatures* internal_default_instance() {
    return reinterpret_cast<const TestInvalidFeatures*>(
        &_TestInvalidFeatures_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(TestInvalidFeatures& a, TestInvalidFeatures& b) { a.Swap(&b); }
  inline void Swap(TestInvalidFeatures* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(TestInvalidFeatures* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  TestInvalidFeatures* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<TestInvalidFeatures>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const TestInvalidFeatures& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const TestInvalidFeatures& from) { TestInvalidFeatures::MergeImpl(*this, from); }

  private:
  static void MergeImpl(::google::protobuf::Message& to_msg,
                        const ::google::protobuf::Message& from_msg);

  public:
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(TestInvalidFeatures* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "pb.TestInvalidFeatures"; }

 protected:
  explicit TestInvalidFeatures(::google::protobuf::Arena* arena);
  TestInvalidFeatures(::google::protobuf::Arena* arena, const TestInvalidFeatures& from);
  const ::google::protobuf::MessageLite::ClassData* GetClassData()
      const final;

 public:
  ::google::protobuf::Metadata GetMetadata() const final;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kRepeatedFeatureFieldNumber = 1,
  };
  // repeated int32 repeated_feature = 1 [retention = RETENTION_RUNTIME, targets = TARGET_TYPE_FIELD, edition_defaults = {
  int repeated_feature_size() const;
  private:
  int _internal_repeated_feature_size() const;

  public:
  void clear_repeated_feature() ;
  ::int32_t repeated_feature(int index) const;
  void set_repeated_feature(int index, ::int32_t value);
  void add_repeated_feature(::int32_t value);
  const ::google::protobuf::RepeatedField<::int32_t>& repeated_feature() const;
  ::google::protobuf::RepeatedField<::int32_t>* mutable_repeated_feature();

  private:
  const ::google::protobuf::RepeatedField<::int32_t>& _internal_repeated_feature() const;
  ::google::protobuf::RepeatedField<::int32_t>* _internal_mutable_repeated_feature();

  public:
  // @@protoc_insertion_point(class_scope:pb.TestInvalidFeatures)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      0, 1, 0,
      0, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from);
    ::google::protobuf::RepeatedField<::int32_t> repeated_feature_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_google_2fprotobuf_2funittest_5finvalid_5ffeatures_2eproto;
};

// ===================================================================



static const int kTestInvalidFieldNumber = 9996;
extern ::google::protobuf::internal::ExtensionIdentifier<
    ::google::protobuf::FeatureSet, ::google::protobuf::internal::MessageTypeTraits< ::pb::TestInvalidFeatures >, 11,
    false>
    test_invalid;

// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// TestInvalidFeatures

// repeated int32 repeated_feature = 1 [retention = RETENTION_RUNTIME, targets = TARGET_TYPE_FIELD, edition_defaults = {
inline int TestInvalidFeatures::_internal_repeated_feature_size() const {
  return _internal_repeated_feature().size();
}
inline int TestInvalidFeatures::repeated_feature_size() const {
  return _internal_repeated_feature_size();
}
inline void TestInvalidFeatures::clear_repeated_feature() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.repeated_feature_.Clear();
}
inline ::int32_t TestInvalidFeatures::repeated_feature(int index) const {
  // @@protoc_insertion_point(field_get:pb.TestInvalidFeatures.repeated_feature)
  return _internal_repeated_feature().Get(index);
}
inline void TestInvalidFeatures::set_repeated_feature(int index, ::int32_t value) {
  _internal_mutable_repeated_feature()->Set(index, value);
  // @@protoc_insertion_point(field_set:pb.TestInvalidFeatures.repeated_feature)
}
inline void TestInvalidFeatures::add_repeated_feature(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _internal_mutable_repeated_feature()->Add(value);
  // @@protoc_insertion_point(field_add:pb.TestInvalidFeatures.repeated_feature)
}
inline const ::google::protobuf::RepeatedField<::int32_t>& TestInvalidFeatures::repeated_feature() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_list:pb.TestInvalidFeatures.repeated_feature)
  return _internal_repeated_feature();
}
inline ::google::protobuf::RepeatedField<::int32_t>* TestInvalidFeatures::mutable_repeated_feature()
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_mutable_list:pb.TestInvalidFeatures.repeated_feature)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  return _internal_mutable_repeated_feature();
}
inline const ::google::protobuf::RepeatedField<::int32_t>& TestInvalidFeatures::_internal_repeated_feature()
    const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.repeated_feature_;
}
inline ::google::protobuf::RepeatedField<::int32_t>* TestInvalidFeatures::_internal_mutable_repeated_feature() {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return &_impl_.repeated_feature_;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace pb


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_google_2fprotobuf_2funittest_5finvalid_5ffeatures_2eproto_2epb_2eh
