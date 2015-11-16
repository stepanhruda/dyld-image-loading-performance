/*
 Copyright 2010-2015 Amazon.com, Inc. or its affiliates. All Rights Reserved.

 Licensed under the Apache License, Version 2.0 (the "License").
 You may not use this file except in compliance with the License.
 A copy of the License is located at

 http://aws.amazon.com/apache2.0

 or in the "license" file accompanying this file. This file is distributed
 on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 express or implied. See the License for the specific language governing
 permissions and limitations under the License.
 */

#import <Foundation/Foundation.h>
#import <AWSCore/AWSNetworking.h>
#import <AWSCore/AWSModel.h>

FOUNDATION_EXPORT NSString *const AWSCognitoSyncErrorDomain;

typedef NS_ENUM(NSInteger, AWSCognitoSyncErrorType) {
    AWSCognitoSyncErrorUnknown,
    AWSCognitoSyncErrorIncompleteSignature,
    AWSCognitoSyncErrorInvalidClientTokenId,
    AWSCognitoSyncErrorMissingAuthenticationToken,
    AWSCognitoSyncErrorAlreadyStreamed,
    AWSCognitoSyncErrorDuplicateRequest,
    AWSCognitoSyncErrorInternalError,
    AWSCognitoSyncErrorInvalidConfiguration,
    AWSCognitoSyncErrorInvalidLambdaFunctionOutput,
    AWSCognitoSyncErrorInvalidParameter,
    AWSCognitoSyncErrorLambdaThrottled,
    AWSCognitoSyncErrorLimitExceeded,
    AWSCognitoSyncErrorNotAuthorized,
    AWSCognitoSyncErrorResourceConflict,
    AWSCognitoSyncErrorResourceNotFound,
    AWSCognitoSyncErrorTooManyRequests,
};

typedef NS_ENUM(NSInteger, AWSCognitoSyncBulkPublishStatus) {
    AWSCognitoSyncBulkPublishStatusUnknown,
    AWSCognitoSyncBulkPublishStatusNotStarted,
    AWSCognitoSyncBulkPublishStatusInProgress,
    AWSCognitoSyncBulkPublishStatusFailed,
    AWSCognitoSyncBulkPublishStatusSucceeded,
};

typedef NS_ENUM(NSInteger, AWSCognitoSyncOperation) {
    AWSCognitoSyncOperationUnknown,
    AWSCognitoSyncOperationReplace,
    AWSCognitoSyncOperationRemove,
};

typedef NS_ENUM(NSInteger, AWSCognitoSyncPlatform) {
    AWSCognitoSyncPlatformUnknown,
    AWSCognitoSyncPlatformApns,
    AWSCognitoSyncPlatformApnsSandbox,
    AWSCognitoSyncPlatformGcm,
    AWSCognitoSyncPlatformAdm,
};

typedef NS_ENUM(NSInteger, AWSCognitoSyncStreamingStatus) {
    AWSCognitoSyncStreamingStatusUnknown,
    AWSCognitoSyncStreamingStatusEnabled,
    AWSCognitoSyncStreamingStatusDisabled,
};

@class AWSCognitoSyncBulkPublishRequest;
@class AWSCognitoSyncBulkPublishResponse;
@class AWSCognitoSyncCognitoStreams;
@class AWSCognitoSyncDataset;
@class AWSCognitoSyncDeleteDatasetRequest;
@class AWSCognitoSyncDeleteDatasetResponse;
@class AWSCognitoSyncDescribeDatasetRequest;
@class AWSCognitoSyncDescribeDatasetResponse;
@class AWSCognitoSyncDescribeIdentityPoolUsageRequest;
@class AWSCognitoSyncDescribeIdentityPoolUsageResponse;
@class AWSCognitoSyncDescribeIdentityUsageRequest;
@class AWSCognitoSyncDescribeIdentityUsageResponse;
@class AWSCognitoSyncGetBulkPublishDetailsRequest;
@class AWSCognitoSyncGetBulkPublishDetailsResponse;
@class AWSCognitoSyncGetCognitoEventsRequest;
@class AWSCognitoSyncGetCognitoEventsResponse;
@class AWSCognitoSyncGetIdentityPoolConfigurationRequest;
@class AWSCognitoSyncGetIdentityPoolConfigurationResponse;
@class AWSCognitoSyncIdentityPoolUsage;
@class AWSCognitoSyncIdentityUsage;
@class AWSCognitoSyncListDatasetsRequest;
@class AWSCognitoSyncListDatasetsResponse;
@class AWSCognitoSyncListIdentityPoolUsageRequest;
@class AWSCognitoSyncListIdentityPoolUsageResponse;
@class AWSCognitoSyncListRecordsRequest;
@class AWSCognitoSyncListRecordsResponse;
@class AWSCognitoSyncPushSync;
@class AWSCognitoSyncRecord;
@class AWSCognitoSyncRecordPatch;
@class AWSCognitoSyncRegisterDeviceRequest;
@class AWSCognitoSyncRegisterDeviceResponse;
@class AWSCognitoSyncSetCognitoEventsRequest;
@class AWSCognitoSyncSetIdentityPoolConfigurationRequest;
@class AWSCognitoSyncSetIdentityPoolConfigurationResponse;
@class AWSCognitoSyncSubscribeToDatasetRequest;
@class AWSCognitoSyncSubscribeToDatasetResponse;
@class AWSCognitoSyncUnsubscribeFromDatasetRequest;
@class AWSCognitoSyncUnsubscribeFromDatasetResponse;
@class AWSCognitoSyncUpdateRecordsRequest;
@class AWSCognitoSyncUpdateRecordsResponse;

/**
 The input for the BulkPublish operation.
 Required parameters: [IdentityPoolId]
 */
@interface AWSCognitoSyncBulkPublishRequest : AWSRequest


/**
 A name-spaced GUID (for example, us-east-1:23EC4050-6AEA-7089-A2DD-08002EXAMPLE) created by Amazon Cognito. GUID generation is unique within a region.
 */
@property (nonatomic, strong) NSString *identityPoolId;

@end

/**
 The output for the BulkPublish operation.
 */
@interface AWSCognitoSyncBulkPublishResponse : AWSModel


/**
 A name-spaced GUID (for example, us-east-1:23EC4050-6AEA-7089-A2DD-08002EXAMPLE) created by Amazon Cognito. GUID generation is unique within a region.
 */
@property (nonatomic, strong) NSString *identityPoolId;

@end

/**
 Configuration options for configure Cognito streams.
 */
@interface AWSCognitoSyncCognitoStreams : AWSModel


/**
 The ARN of the role Amazon Cognito can assume in order to publish to the stream. This role must grant access to Amazon Cognito (cognito-sync) to invoke PutRecord on your Cognito stream.
 */
@property (nonatomic, strong) NSString *roleArn;

/**
 The name of the Cognito stream to receive updates. This stream must be in the developers account and in the same region as the identity pool.
 */
@property (nonatomic, strong) NSString *streamName;

/**
 Status of the Cognito streams. Valid values are: <p>ENABLED - Streaming of updates to identity pool is enabled.</p><p>DISABLED - Streaming of updates to identity pool is disabled. Bulk publish will also fail if StreamingStatus is DISABLED.</p>
 */
@property (nonatomic, assign) AWSCognitoSyncStreamingStatus streamingStatus;

@end

/**
 A collection of data for an identity pool. An identity pool can have multiple datasets. A dataset is per identity and can be general or associated with a particular entity in an application (like a saved game). Datasets are automatically created if they don't exist. Data is synced by dataset, and a dataset can hold up to 1MB of key-value pairs.
 */
@interface AWSCognitoSyncDataset : AWSModel


/**
 Date on which the dataset was created.
 */
@property (nonatomic, strong) NSDate *creationDate;

/**
 Total size in bytes of the records in this dataset.
 */
@property (nonatomic, strong) NSNumber *dataStorage;

/**
 A string of up to 128 characters. Allowed characters are a-z, A-Z, 0-9, '_' (underscore), '-' (dash), and '.' (dot).
 */
@property (nonatomic, strong) NSString *datasetName;

/**
 A name-spaced GUID (for example, us-east-1:23EC4050-6AEA-7089-A2DD-08002EXAMPLE) created by Amazon Cognito. GUID generation is unique within a region.
 */
@property (nonatomic, strong) NSString *identityId;

/**
 The device that made the last change to this dataset.
 */
@property (nonatomic, strong) NSString *lastModifiedBy;

/**
 Date when the dataset was last modified.
 */
@property (nonatomic, strong) NSDate *lastModifiedDate;

/**
 Number of records in this dataset.
 */
@property (nonatomic, strong) NSNumber *numRecords;

@end

/**
 A request to delete the specific dataset.
 Required parameters: [IdentityPoolId, IdentityId, DatasetName]
 */
@interface AWSCognitoSyncDeleteDatasetRequest : AWSRequest


/**
 A string of up to 128 characters. Allowed characters are a-z, A-Z, 0-9, '_' (underscore), '-' (dash), and '.' (dot).
 */
@property (nonatomic, strong) NSString *datasetName;

/**
 A name-spaced GUID (for example, us-east-1:23EC4050-6AEA-7089-A2DD-08002EXAMPLE) created by Amazon Cognito. GUID generation is unique within a region.
 */
@property (nonatomic, strong) NSString *identityId;

/**
 A name-spaced GUID (for example, us-east-1:23EC4050-6AEA-7089-A2DD-08002EXAMPLE) created by Amazon Cognito. GUID generation is unique within a region.
 */
@property (nonatomic, strong) NSString *identityPoolId;

@end

/**
 Response to a successful DeleteDataset request.
 */
@interface AWSCognitoSyncDeleteDatasetResponse : AWSModel


/**
 A collection of data for an identity pool. An identity pool can have multiple datasets. A dataset is per identity and can be general or associated with a particular entity in an application (like a saved game). Datasets are automatically created if they don't exist. Data is synced by dataset, and a dataset can hold up to 1MB of key-value pairs.
 */
@property (nonatomic, strong) AWSCognitoSyncDataset *dataset;

@end

/**
 A request for meta data about a dataset (creation date, number of records, size) by owner and dataset name.
 Required parameters: [IdentityPoolId, IdentityId, DatasetName]
 */
@interface AWSCognitoSyncDescribeDatasetRequest : AWSRequest


/**
 A string of up to 128 characters. Allowed characters are a-z, A-Z, 0-9, '_' (underscore), '-' (dash), and '.' (dot).
 */
@property (nonatomic, strong) NSString *datasetName;

/**
 A name-spaced GUID (for example, us-east-1:23EC4050-6AEA-7089-A2DD-08002EXAMPLE) created by Amazon Cognito. GUID generation is unique within a region.
 */
@property (nonatomic, strong) NSString *identityId;

/**
 A name-spaced GUID (for example, us-east-1:23EC4050-6AEA-7089-A2DD-08002EXAMPLE) created by Amazon Cognito. GUID generation is unique within a region.
 */
@property (nonatomic, strong) NSString *identityPoolId;

@end

/**
 Response to a successful DescribeDataset request.
 */
@interface AWSCognitoSyncDescribeDatasetResponse : AWSModel


/**
 Meta data for a collection of data for an identity. An identity can have multiple datasets. A dataset can be general or associated with a particular entity in an application (like a saved game). Datasets are automatically created if they don't exist. Data is synced by dataset, and a dataset can hold up to 1MB of key-value pairs.
 */
@property (nonatomic, strong) AWSCognitoSyncDataset *dataset;

@end

/**
 A request for usage information about the identity pool.
 Required parameters: [IdentityPoolId]
 */
@interface AWSCognitoSyncDescribeIdentityPoolUsageRequest : AWSRequest


/**
 A name-spaced GUID (for example, us-east-1:23EC4050-6AEA-7089-A2DD-08002EXAMPLE) created by Amazon Cognito. GUID generation is unique within a region.
 */
@property (nonatomic, strong) NSString *identityPoolId;

@end

/**
 Response to a successful DescribeIdentityPoolUsage request.
 */
@interface AWSCognitoSyncDescribeIdentityPoolUsageResponse : AWSModel


/**
 Information about the usage of the identity pool.
 */
@property (nonatomic, strong) AWSCognitoSyncIdentityPoolUsage *identityPoolUsage;

@end

/**
 A request for information about the usage of an identity pool.
 Required parameters: [IdentityPoolId, IdentityId]
 */
@interface AWSCognitoSyncDescribeIdentityUsageRequest : AWSRequest


/**
 A name-spaced GUID (for example, us-east-1:23EC4050-6AEA-7089-A2DD-08002EXAMPLE) created by Amazon Cognito. GUID generation is unique within a region.
 */
@property (nonatomic, strong) NSString *identityId;

/**
 A name-spaced GUID (for example, us-east-1:23EC4050-6AEA-7089-A2DD-08002EXAMPLE) created by Amazon Cognito. GUID generation is unique within a region.
 */
@property (nonatomic, strong) NSString *identityPoolId;

@end

/**
 The response to a successful DescribeIdentityUsage request.
 */
@interface AWSCognitoSyncDescribeIdentityUsageResponse : AWSModel


/**
 Usage information for the identity.
 */
@property (nonatomic, strong) AWSCognitoSyncIdentityUsage *identityUsage;

@end

/**
 The input for the GetBulkPublishDetails operation.
 Required parameters: [IdentityPoolId]
 */
@interface AWSCognitoSyncGetBulkPublishDetailsRequest : AWSRequest


/**
 A name-spaced GUID (for example, us-east-1:23EC4050-6AEA-7089-A2DD-08002EXAMPLE) created by Amazon Cognito. GUID generation is unique within a region.
 */
@property (nonatomic, strong) NSString *identityPoolId;

@end

/**
 The output for the GetBulkPublishDetails operation.
 */
@interface AWSCognitoSyncGetBulkPublishDetailsResponse : AWSModel


/**
 If BulkPublishStatus is SUCCEEDED, the time the last bulk publish operation completed.
 */
@property (nonatomic, strong) NSDate *bulkPublishCompleteTime;

/**
 The date/time at which the last bulk publish was initiated.
 */
@property (nonatomic, strong) NSDate *bulkPublishStartTime;

/**
 Status of the last bulk publish operation, valid values are: <p>NOT_STARTED - No bulk publish has been requested for this identity pool</p><p>IN_PROGRESS - Data is being published to the configured stream</p><p>SUCCEEDED - All data for the identity pool has been published to the configured stream</p><p>FAILED - Some portion of the data has failed to publish, check FailureMessage for the cause.</p>
 */
@property (nonatomic, assign) AWSCognitoSyncBulkPublishStatus bulkPublishStatus;

/**
 If BulkPublishStatus is FAILED this field will contain the error message that caused the bulk publish to fail.
 */
@property (nonatomic, strong) NSString *failureMessage;

/**
 A name-spaced GUID (for example, us-east-1:23EC4050-6AEA-7089-A2DD-08002EXAMPLE) created by Amazon Cognito. GUID generation is unique within a region.
 */
@property (nonatomic, strong) NSString *identityPoolId;

@end

/**
 <p>A request for a list of the configured Cognito Events</p>
 Required parameters: [IdentityPoolId]
 */
@interface AWSCognitoSyncGetCognitoEventsRequest : AWSRequest


/**
 <p>The Cognito Identity Pool ID for the request</p>
 */
@property (nonatomic, strong) NSString *identityPoolId;

@end

/**
 <p>The response from the GetCognitoEvents request</p>
 */
@interface AWSCognitoSyncGetCognitoEventsResponse : AWSModel


/**
 <p>The Cognito Events returned from the GetCognitoEvents request</p>
 */
@property (nonatomic, strong) NSDictionary *events;

@end

/**
 <p>The input for the GetIdentityPoolConfiguration operation.</p>
 Required parameters: [IdentityPoolId]
 */
@interface AWSCognitoSyncGetIdentityPoolConfigurationRequest : AWSRequest


/**
 <p>A name-spaced GUID (for example, us-east-1:23EC4050-6AEA-7089-A2DD-08002EXAMPLE) created by Amazon Cognito. This is the ID of the pool for which to return a configuration.</p>
 */
@property (nonatomic, strong) NSString *identityPoolId;

@end

/**
 <p>The output for the GetIdentityPoolConfiguration operation.</p>
 */
@interface AWSCognitoSyncGetIdentityPoolConfigurationResponse : AWSModel


/**
 Options to apply to this identity pool for Amazon Cognito streams.
 */
@property (nonatomic, strong) AWSCognitoSyncCognitoStreams *cognitoStreams;

/**
 <p>A name-spaced GUID (for example, us-east-1:23EC4050-6AEA-7089-A2DD-08002EXAMPLE) created by Amazon Cognito.</p>
 */
@property (nonatomic, strong) NSString *identityPoolId;

/**
 <p>Options to apply to this identity pool for push synchronization.</p>
 */
@property (nonatomic, strong) AWSCognitoSyncPushSync *pushSync;

@end

/**
 Usage information for the identity pool.
 */
@interface AWSCognitoSyncIdentityPoolUsage : AWSModel


/**
 Data storage information for the identity pool.
 */
@property (nonatomic, strong) NSNumber *dataStorage;

/**
 A name-spaced GUID (for example, us-east-1:23EC4050-6AEA-7089-A2DD-08002EXAMPLE) created by Amazon Cognito. GUID generation is unique within a region.
 */
@property (nonatomic, strong) NSString *identityPoolId;

/**
 Date on which the identity pool was last modified.
 */
@property (nonatomic, strong) NSDate *lastModifiedDate;

/**
 Number of sync sessions for the identity pool.
 */
@property (nonatomic, strong) NSNumber *syncSessionsCount;

@end

/**
 Usage information for the identity.
 */
@interface AWSCognitoSyncIdentityUsage : AWSModel


/**
 Total data storage for this identity.
 */
@property (nonatomic, strong) NSNumber *dataStorage;

/**
 Number of datasets for the identity.
 */
@property (nonatomic, strong) NSNumber *datasetCount;

/**
 A name-spaced GUID (for example, us-east-1:23EC4050-6AEA-7089-A2DD-08002EXAMPLE) created by Amazon Cognito. GUID generation is unique within a region.
 */
@property (nonatomic, strong) NSString *identityId;

/**
 A name-spaced GUID (for example, us-east-1:23EC4050-6AEA-7089-A2DD-08002EXAMPLE) created by Amazon Cognito. GUID generation is unique within a region.
 */
@property (nonatomic, strong) NSString *identityPoolId;

/**
 Date on which the identity was last modified.
 */
@property (nonatomic, strong) NSDate *lastModifiedDate;

@end

/**
 Request for a list of datasets for an identity.
 Required parameters: [IdentityId, IdentityPoolId]
 */
@interface AWSCognitoSyncListDatasetsRequest : AWSRequest


/**
 A name-spaced GUID (for example, us-east-1:23EC4050-6AEA-7089-A2DD-08002EXAMPLE) created by Amazon Cognito. GUID generation is unique within a region.
 */
@property (nonatomic, strong) NSString *identityId;

/**
 A name-spaced GUID (for example, us-east-1:23EC4050-6AEA-7089-A2DD-08002EXAMPLE) created by Amazon Cognito. GUID generation is unique within a region.
 */
@property (nonatomic, strong) NSString *identityPoolId;

/**
 The maximum number of results to be returned.
 */
@property (nonatomic, strong) NSNumber *maxResults;

/**
 A pagination token for obtaining the next page of results.
 */
@property (nonatomic, strong) NSString *nextToken;

@end

/**
 Returned for a successful ListDatasets request.
 */
@interface AWSCognitoSyncListDatasetsResponse : AWSModel


/**
 Number of datasets returned.
 */
@property (nonatomic, strong) NSNumber *count;

/**
 A set of datasets.
 */
@property (nonatomic, strong) NSArray *datasets;

/**
 A pagination token for obtaining the next page of results.
 */
@property (nonatomic, strong) NSString *nextToken;

@end

/**
 A request for usage information on an identity pool.
 */
@interface AWSCognitoSyncListIdentityPoolUsageRequest : AWSRequest


/**
 The maximum number of results to be returned.
 */
@property (nonatomic, strong) NSNumber *maxResults;

/**
 A pagination token for obtaining the next page of results.
 */
@property (nonatomic, strong) NSString *nextToken;

@end

/**
 Returned for a successful ListIdentityPoolUsage request.
 */
@interface AWSCognitoSyncListIdentityPoolUsageResponse : AWSModel


/**
 Total number of identities for the identity pool.
 */
@property (nonatomic, strong) NSNumber *count;

/**
 Usage information for the identity pools.
 */
@property (nonatomic, strong) NSArray *identityPoolUsages;

/**
 The maximum number of results to be returned.
 */
@property (nonatomic, strong) NSNumber *maxResults;

/**
 A pagination token for obtaining the next page of results.
 */
@property (nonatomic, strong) NSString *nextToken;

@end

/**
 A request for a list of records.
 Required parameters: [IdentityPoolId, IdentityId, DatasetName]
 */
@interface AWSCognitoSyncListRecordsRequest : AWSRequest


/**
 A string of up to 128 characters. Allowed characters are a-z, A-Z, 0-9, '_' (underscore), '-' (dash), and '.' (dot).
 */
@property (nonatomic, strong) NSString *datasetName;

/**
 A name-spaced GUID (for example, us-east-1:23EC4050-6AEA-7089-A2DD-08002EXAMPLE) created by Amazon Cognito. GUID generation is unique within a region.
 */
@property (nonatomic, strong) NSString *identityId;

/**
 A name-spaced GUID (for example, us-east-1:23EC4050-6AEA-7089-A2DD-08002EXAMPLE) created by Amazon Cognito. GUID generation is unique within a region.
 */
@property (nonatomic, strong) NSString *identityPoolId;

/**
 The last server sync count for this record.
 */
@property (nonatomic, strong) NSNumber *lastSyncCount;

/**
 The maximum number of results to be returned.
 */
@property (nonatomic, strong) NSNumber *maxResults;

/**
 A pagination token for obtaining the next page of results.
 */
@property (nonatomic, strong) NSString *nextToken;

/**
 A token containing a session ID, identity ID, and expiration.
 */
@property (nonatomic, strong) NSString *syncSessionToken;

@end

/**
 Returned for a successful ListRecordsRequest.
 */
@interface AWSCognitoSyncListRecordsResponse : AWSModel


/**
 Total number of records.
 */
@property (nonatomic, strong) NSNumber *count;

/**
 A boolean value specifying whether to delete the dataset locally.
 */
@property (nonatomic, strong) NSNumber *datasetDeletedAfterRequestedSyncCount;

/**
 Indicates whether the dataset exists.
 */
@property (nonatomic, strong) NSNumber *datasetExists;

/**
 Server sync count for this dataset.
 */
@property (nonatomic, strong) NSNumber *datasetSyncCount;

/**
 The user/device that made the last change to this record.
 */
@property (nonatomic, strong) NSString *lastModifiedBy;

/**
 Names of merged datasets.
 */
@property (nonatomic, strong) NSArray *mergedDatasetNames;

/**
 A pagination token for obtaining the next page of results.
 */
@property (nonatomic, strong) NSString *nextToken;

/**
 A list of all records.
 */
@property (nonatomic, strong) NSArray *records;

/**
 A token containing a session ID, identity ID, and expiration.
 */
@property (nonatomic, strong) NSString *syncSessionToken;

@end

/**
 <p>Configuration options to be applied to the identity pool.</p>
 */
@interface AWSCognitoSyncPushSync : AWSModel


/**
 <p>List of SNS platform application ARNs that could be used by clients.</p>
 */
@property (nonatomic, strong) NSArray *applicationArns;

/**
 <p>A role configured to allow Cognito to call SNS on behalf of the developer.</p>
 */
@property (nonatomic, strong) NSString *roleArn;

@end

/**
 The basic data structure of a dataset.
 */
@interface AWSCognitoSyncRecord : AWSModel


/**
 The last modified date of the client device.
 */
@property (nonatomic, strong) NSDate *deviceLastModifiedDate;

/**
 The key for the record.
 */
@property (nonatomic, strong) NSString *key;

/**
 The user/device that made the last change to this record.
 */
@property (nonatomic, strong) NSString *lastModifiedBy;

/**
 The date on which the record was last modified.
 */
@property (nonatomic, strong) NSDate *lastModifiedDate;

/**
 The server sync count for this record.
 */
@property (nonatomic, strong) NSNumber *syncCount;

/**
 The value for the record.
 */
@property (nonatomic, strong) NSString *value;

@end

/**
 An update operation for a record.
 Required parameters: [Op, Key, SyncCount]
 */
@interface AWSCognitoSyncRecordPatch : AWSModel


/**
 The last modified date of the client device.
 */
@property (nonatomic, strong) NSDate *deviceLastModifiedDate;

/**
 The key associated with the record patch.
 */
@property (nonatomic, strong) NSString *key;

/**
 An operation, either replace or remove.
 */
@property (nonatomic, assign) AWSCognitoSyncOperation op;

/**
 Last known server sync count for this record. Set to 0 if unknown.
 */
@property (nonatomic, strong) NSNumber *syncCount;

/**
 The value associated with the record patch.
 */
@property (nonatomic, strong) NSString *value;

@end

/**
 <p>A request to RegisterDevice.</p>
 Required parameters: [IdentityPoolId, IdentityId, Platform, Token]
 */
@interface AWSCognitoSyncRegisterDeviceRequest : AWSRequest


/**
 <p>The unique ID for this identity.</p>
 */
@property (nonatomic, strong) NSString *identityId;

/**
 <p>A name-spaced GUID (for example, us-east-1:23EC4050-6AEA-7089-A2DD-08002EXAMPLE) created by Amazon Cognito. Here, the ID of the pool that the identity belongs to.</p>
 */
@property (nonatomic, strong) NSString *identityPoolId;

/**
 <p>The SNS platform type (e.g. GCM, SDM, APNS, APNS_SANDBOX).</p>
 */
@property (nonatomic, assign) AWSCognitoSyncPlatform platform;

/**
 <p>The push token.</p>
 */
@property (nonatomic, strong) NSString *token;

@end

/**
 <p>Response to a RegisterDevice request.</p>
 */
@interface AWSCognitoSyncRegisterDeviceResponse : AWSModel


/**
 <p>The unique ID generated for this device by Cognito.</p>
 */
@property (nonatomic, strong) NSString *deviceId;

@end

/**
 <p>A request to configure Cognito Events"</p>"
 Required parameters: [IdentityPoolId, Events]
 */
@interface AWSCognitoSyncSetCognitoEventsRequest : AWSRequest


/**
 <p>The events to configure</p>
 */
@property (nonatomic, strong) NSDictionary *events;

/**
 <p>The Cognito Identity Pool to use when configuring Cognito Events</p>
 */
@property (nonatomic, strong) NSString *identityPoolId;

@end

/**
 <p>The input for the SetIdentityPoolConfiguration operation.</p>
 Required parameters: [IdentityPoolId]
 */
@interface AWSCognitoSyncSetIdentityPoolConfigurationRequest : AWSRequest


/**
 Options to apply to this identity pool for Amazon Cognito streams.
 */
@property (nonatomic, strong) AWSCognitoSyncCognitoStreams *cognitoStreams;

/**
 <p>A name-spaced GUID (for example, us-east-1:23EC4050-6AEA-7089-A2DD-08002EXAMPLE) created by Amazon Cognito. This is the ID of the pool to modify.</p>
 */
@property (nonatomic, strong) NSString *identityPoolId;

/**
 <p>Options to apply to this identity pool for push synchronization.</p>
 */
@property (nonatomic, strong) AWSCognitoSyncPushSync *pushSync;

@end

/**
 <p>The output for the SetIdentityPoolConfiguration operation</p>
 */
@interface AWSCognitoSyncSetIdentityPoolConfigurationResponse : AWSModel


/**
 Options to apply to this identity pool for Amazon Cognito streams.
 */
@property (nonatomic, strong) AWSCognitoSyncCognitoStreams *cognitoStreams;

/**
 <p>A name-spaced GUID (for example, us-east-1:23EC4050-6AEA-7089-A2DD-08002EXAMPLE) created by Amazon Cognito.</p>
 */
@property (nonatomic, strong) NSString *identityPoolId;

/**
 <p>Options to apply to this identity pool for push synchronization.</p>
 */
@property (nonatomic, strong) AWSCognitoSyncPushSync *pushSync;

@end

/**
 <p>A request to SubscribeToDatasetRequest.</p>
 Required parameters: [IdentityPoolId, IdentityId, DatasetName, DeviceId]
 */
@interface AWSCognitoSyncSubscribeToDatasetRequest : AWSRequest


/**
 <p>The name of the dataset to subcribe to.</p>
 */
@property (nonatomic, strong) NSString *datasetName;

/**
 <p>The unique ID generated for this device by Cognito.</p>
 */
@property (nonatomic, strong) NSString *deviceId;

/**
 <p>Unique ID for this identity.</p>
 */
@property (nonatomic, strong) NSString *identityId;

/**
 <p>A name-spaced GUID (for example, us-east-1:23EC4050-6AEA-7089-A2DD-08002EXAMPLE) created by Amazon Cognito. The ID of the pool to which the identity belongs.</p>
 */
@property (nonatomic, strong) NSString *identityPoolId;

@end

/**
 <p>Response to a SubscribeToDataset request.</p>
 */
@interface AWSCognitoSyncSubscribeToDatasetResponse : AWSModel


@end

/**
 <p>A request to UnsubscribeFromDataset.</p>
 Required parameters: [IdentityPoolId, IdentityId, DatasetName, DeviceId]
 */
@interface AWSCognitoSyncUnsubscribeFromDatasetRequest : AWSRequest


/**
 <p>The name of the dataset from which to unsubcribe.</p>
 */
@property (nonatomic, strong) NSString *datasetName;

/**
 <p>The unique ID generated for this device by Cognito.</p>
 */
@property (nonatomic, strong) NSString *deviceId;

/**
 <p>Unique ID for this identity.</p>
 */
@property (nonatomic, strong) NSString *identityId;

/**
 <p>A name-spaced GUID (for example, us-east-1:23EC4050-6AEA-7089-A2DD-08002EXAMPLE) created by Amazon Cognito. The ID of the pool to which this identity belongs.</p>
 */
@property (nonatomic, strong) NSString *identityPoolId;

@end

/**
 <p>Response to an UnsubscribeFromDataset request.</p>
 */
@interface AWSCognitoSyncUnsubscribeFromDatasetResponse : AWSModel


@end

/**
 A request to post updates to records or add and delete records for a dataset and user.
 Required parameters: [IdentityPoolId, IdentityId, DatasetName, SyncSessionToken]
 */
@interface AWSCognitoSyncUpdateRecordsRequest : AWSRequest


/**
 Intended to supply a device ID that will populate the lastModifiedBy field referenced in other methods. The ClientContext field is not yet implemented.
 */
@property (nonatomic, strong) NSString *clientContext;

/**
 A string of up to 128 characters. Allowed characters are a-z, A-Z, 0-9, '_' (underscore), '-' (dash), and '.' (dot).
 */
@property (nonatomic, strong) NSString *datasetName;

/**
 <p>The unique ID generated for this device by Cognito.</p>
 */
@property (nonatomic, strong) NSString *deviceId;

/**
 A name-spaced GUID (for example, us-east-1:23EC4050-6AEA-7089-A2DD-08002EXAMPLE) created by Amazon Cognito. GUID generation is unique within a region.
 */
@property (nonatomic, strong) NSString *identityId;

/**
 A name-spaced GUID (for example, us-east-1:23EC4050-6AEA-7089-A2DD-08002EXAMPLE) created by Amazon Cognito. GUID generation is unique within a region.
 */
@property (nonatomic, strong) NSString *identityPoolId;

/**
 A list of patch operations.
 */
@property (nonatomic, strong) NSArray *recordPatches;

/**
 The SyncSessionToken returned by a previous call to ListRecords for this dataset and identity.
 */
@property (nonatomic, strong) NSString *syncSessionToken;

@end

/**
 Returned for a successful UpdateRecordsRequest.
 */
@interface AWSCognitoSyncUpdateRecordsResponse : AWSModel


/**
 A list of records that have been updated.
 */
@property (nonatomic, strong) NSArray *records;

@end
