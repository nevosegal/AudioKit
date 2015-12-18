//
//  highPassButterworthFilter.swift
//  AudioKit For iOS
//
//  Autogenerated by scripts by Aurelius Prochazka. Do not edit directly.
//  Copyright © 2015 AudioKit. All rights reserved.
//

import Foundation

extension AKOperation {

    /** highPassButterworthFilter: A high-pass Butterworth filter. - These filters are Butterworth second-order IIR filters. They offer an almost
     flat passband and very good precision and stopband attenuation.
     - Parameter cutoffFrequency: Cutoff frequency. (in Hertz) (Default: 500, Minimum: 12.0, Maximum: 20000.0)
     */
    public mutating func highPassButterworthFilter(
        cutoffFrequency cutoffFrequency: AKOperation = 500.ak) {
            self = self.highPassButterworthFiltered(cutoffFrequency: cutoffFrequency)
    }
    
    /** highPassButterworthFiltered: A high-pass Butterworth filter. - These filters are Butterworth second-order IIR filters. They offer an almost
 flat passband and very good precision and stopband attenuation.
     - returns: AKOperation
     - Parameter cutoffFrequency: Cutoff frequency. (in Hertz) (Default: 500, Minimum: 12.0, Maximum: 20000.0)
     */
    public func highPassButterworthFiltered(
        cutoffFrequency cutoffFrequency: AKOperation = 500.ak) -> AKOperation {
            return AKOperation("\(self)\(cutoffFrequency)buthp")
    }
}
