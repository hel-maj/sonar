/* ===== 23aabdfa0 __parents_main__:271 ===== */
/* ghidra_name=FUN_23aabdfa0 entry=23aabdfa0 size=11761 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23aabdfa0(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  code *pcVar5;
  byte bVar6;
  undefined8 uVar7;
  int iVar8;
  uint uVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong lVar14;
  undefined8 uVar15;
  longlong lVar16;
  longlong *plVar17;
  longlong *plVar18;
  longlong *plVar19;
  code *pcVar20;
  code *pcVar21;
  longlong *plVar22;
  longlong *plVar23;
  code *pcVar24;
  undefined4 uVar25;
  code *pcStack_108;
  longlong *plStack_100;
  longlong *plStack_f8;
  longlong *plStack_f0;
  longlong *plStack_e8;
  longlong *plStack_e0;
  longlong *plStack_d8;
  code *pcStack_c8;
  code *pcStack_b8;
  code *pcStack_a8;
  undefined8 uStack_a0;
  undefined1 auStack_98 [16];
  code *apcStack_88 [2];
  longlong *plStack_78;
  code *pcStack_70;
  code *pcStack_68;
  
  plVar10 = _DAT_23ed90a70;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (_DAT_23ed90a70 == (longlong *)0x0) {
LAB_23aabdff9:
    _DAT_23ed90a70 = (longlong *)FUN_23e91f3b0(param_1,DAT_23ed90a68,DAT_23ed90b40);
  }
  else {
    lVar16 = *_DAT_23ed90a70;
    if (1 < lVar16) {
      *_DAT_23ed90a70 = lVar16 + -1;
      goto LAB_23aabdff9;
    }
    if (_DAT_23ed90a70[2] != 0) {
      *_DAT_23ed90a70 = lVar16 + -1;
      if (lVar16 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23aabdff9;
    }
  }
  plVar3 = _DAT_23ed90a70;
  lVar16 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23ed90a70 + 9;
  lVar14 = *(longlong *)(lVar16 + 8);
  _DAT_23ed90a70[0xf] = lVar14;
  *(longlong **)(lVar16 + 8) = plVar10;
  if ((lVar14 != 0) &&
     (((*(char *)(lVar14 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar14 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar14 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar14 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar14 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar15 = DAT_23ed8f510;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,uVar15);
  pcStack_108 = _Py_NoneStruct_exref;
  if (plVar10 == (longlong *)0x0) {
    plVar22 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plVar10 = *(longlong **)(param_1 + 0x60);
    pcVar20 = *(code **)(param_1 + 0x68);
    pcVar24 = *(code **)(param_1 + 0x70);
    plStack_e8 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar25 = 0x113;
    plStack_e0 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar12 = (longlong *)0x0;
  }
  else {
    *(undefined4 *)(plVar3 + 5) = 0x113;
    plVar11 = (longlong *)FUN_23e91bfe0(param_1,plVar10,_DAT_23ed8f6c8);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    pcStack_108 = _Py_NoneStruct_exref;
    if (plVar11 == (longlong *)0x0) {
      pcVar24 = *(code **)(param_1 + 0x70);
      plVar22 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar12 = (longlong *)0x0;
      plVar10 = *(longlong **)(param_1 + 0x60);
      pcVar20 = *(code **)(param_1 + 0x68);
      plStack_e8 = (longlong *)0x0;
      uVar25 = 0x113;
      plStack_e0 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_f8 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    }
    else {
      plVar10 = (longlong *)FUN_23e8bc2f0(plVar11,DAT_23ed6ce40);
      pcStack_108 = _Py_NoneStruct_exref;
      if (plVar10 == (longlong *)0x0) {
        plVar22 = (longlong *)0x0;
        plVar12 = (longlong *)0x0;
        plVar10 = *(longlong **)(param_1 + 0x60);
        pcVar20 = *(code **)(param_1 + 0x68);
        pcVar24 = *(code **)(param_1 + 0x70);
        plStack_e8 = (longlong *)0x0;
        uVar25 = 0x116;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plStack_e0 = (longlong *)0x0;
        plStack_d8 = (longlong *)0x0;
        plStack_f0 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        plStack_100 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar13 = (longlong *)0x0;
      }
      else {
        *(undefined4 *)(plVar3 + 5) = 0x116;
        plVar12 = (longlong *)FUN_23e9557e0(param_1,plVar10,_DAT_23ed8f6d0);
        *plVar10 = *plVar10 + -1;
        pcStack_108 = _Py_NoneStruct_exref;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
          pcStack_108 = _Py_NoneStruct_exref;
        }
        _Py_NoneStruct_exref = pcStack_108;
        if (plVar12 == (longlong *)0x0) {
          plVar22 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          plVar10 = *(longlong **)(param_1 + 0x60);
          pcVar20 = *(code **)(param_1 + 0x68);
          pcVar24 = *(code **)(param_1 + 0x70);
          plStack_e8 = (longlong *)0x0;
          uVar25 = 0x116;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plStack_e0 = (longlong *)0x0;
          plStack_d8 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          plStack_f8 = (longlong *)0x0;
          plStack_100 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        }
        else {
          plVar10 = (longlong *)FUN_23e8bc2f0(plVar11,DAT_23ed6ce40);
          plVar13 = (longlong *)0x0;
          if (plVar10 == (longlong *)0x0) {
LAB_23aabef20:
            pcStack_108 = _Py_NoneStruct_exref;
            plVar10 = *(longlong **)(param_1 + 0x60);
            pcVar20 = *(code **)(param_1 + 0x68);
            pcVar24 = *(code **)(param_1 + 0x70);
            plVar22 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            uVar25 = 0x117;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plStack_e8 = (longlong *)0x0;
            plStack_e0 = (longlong *)0x0;
            plStack_d8 = (longlong *)0x0;
            plStack_f0 = (longlong *)0x0;
            plStack_f8 = (longlong *)0x0;
            plStack_100 = (longlong *)0x0;
          }
          else {
            *(undefined4 *)(plVar3 + 5) = 0x117;
            plVar13 = (longlong *)FUN_23e9557e0(param_1,plVar10,_DAT_23ed8f6d8);
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            pcStack_108 = _Py_NoneStruct_exref;
            if (plVar13 == (longlong *)0x0) {
              plVar10 = *(longlong **)(param_1 + 0x60);
              pcVar20 = *(code **)(param_1 + 0x68);
              pcVar24 = *(code **)(param_1 + 0x70);
              plVar13 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              uVar25 = 0x117;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plStack_e8 = (longlong *)0x0;
              plStack_e0 = (longlong *)0x0;
              plStack_d8 = (longlong *)0x0;
              plStack_f0 = (longlong *)0x0;
              plStack_f8 = (longlong *)0x0;
              plStack_100 = (longlong *)0x0;
              plVar22 = (longlong *)0x0;
            }
            else {
              plVar10 = (longlong *)FUN_23e8bc2f0(plVar13,_DAT_23ed8f6e0);
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              pcStack_108 = _Py_NoneStruct_exref;
              if (plVar10 == (longlong *)0x0) {
                plVar22 = (longlong *)0x0;
                plVar13 = (longlong *)0x0;
                plVar10 = *(longlong **)(param_1 + 0x60);
                pcVar20 = *(code **)(param_1 + 0x68);
                pcVar24 = *(code **)(param_1 + 0x70);
                plStack_e8 = (longlong *)0x0;
                uVar25 = 0x117;
                *(undefined8 *)(param_1 + 0x70) = 0;
                plStack_e0 = (longlong *)0x0;
                plStack_d8 = (longlong *)0x0;
                plStack_f0 = (longlong *)0x0;
                plStack_f8 = (longlong *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plStack_100 = (longlong *)0x0;
              }
              else {
                *(undefined4 *)(plVar3 + 5) = 0x117;
                plVar13 = (longlong *)FUN_23e91a870(param_1,plVar10);
                lVar16 = *plVar10;
                *plVar10 = lVar16 + -1;
                if (lVar16 + -1 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                }
                if (plVar13 == (longlong *)0x0) goto LAB_23aabef20;
                iVar8 = FUN_23a35f020(plVar12);
                if (iVar8 == -1) {
LAB_23aabf850:
                  pcStack_108 = _Py_NoneStruct_exref;
                  plVar10 = *(longlong **)(param_1 + 0x60);
                  pcVar20 = *(code **)(param_1 + 0x68);
                  pcVar24 = *(code **)(param_1 + 0x70);
                  plVar22 = (longlong *)0x0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  uVar25 = 0x11a;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  plStack_e8 = (longlong *)0x0;
                  plStack_e0 = (longlong *)0x0;
                  plStack_d8 = (longlong *)0x0;
                  plStack_f0 = (longlong *)0x0;
                  plStack_f8 = (longlong *)0x0;
                  plStack_100 = (longlong *)0x0;
                }
                else {
                  if (iVar8 == 0) {
                    iVar8 = FUN_23a35f020(plVar13);
                    bVar6 = (byte)iVar8;
                    if (iVar8 == -1) goto LAB_23aabf850;
                  }
                  else {
                    bVar6 = (byte)iVar8;
                  }
                  if (((bVar6 ^ 1) & 1) == 0) {
                    plVar10 = (longlong *)FUN_23e8bc2f0(plVar11,DAT_23ed6ce40);
                    plVar22 = (longlong *)0x0;
                    if (plVar10 == (longlong *)0x0) {
LAB_23aabfbfb:
                      pcStack_108 = _Py_NoneStruct_exref;
                      plVar10 = *(longlong **)(param_1 + 0x60);
                      pcVar20 = *(code **)(param_1 + 0x68);
                      plStack_e8 = (longlong *)0x0;
                      pcVar24 = *(code **)(param_1 + 0x70);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      uVar25 = 0x11f;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      plStack_e0 = (longlong *)0x0;
                      plStack_d8 = (longlong *)0x0;
                      plStack_f0 = (longlong *)0x0;
                      plStack_f8 = (longlong *)0x0;
                      plStack_100 = (longlong *)0x0;
                    }
                    else {
                      *(undefined4 *)(plVar3 + 5) = 0x11f;
                      plVar22 = (longlong *)FUN_23e9557e0(param_1,plVar10,_DAT_23ed8f6f8);
                      *plVar10 = *plVar10 + -1;
                      if (*plVar10 == 0) {
                        (**(code **)(plVar10[1] + 0x30))(plVar10);
                      }
                      pcStack_108 = _Py_NoneStruct_exref;
                      if (plVar22 == (longlong *)0x0) {
                        plVar10 = *(longlong **)(param_1 + 0x60);
                        pcVar20 = *(code **)(param_1 + 0x68);
                        pcVar24 = *(code **)(param_1 + 0x70);
                        plVar22 = (longlong *)0x0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        uVar25 = 0x11f;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        plStack_e8 = (longlong *)0x0;
                        plStack_e0 = (longlong *)0x0;
                        plStack_d8 = (longlong *)0x0;
                        plStack_f0 = (longlong *)0x0;
                        plStack_f8 = (longlong *)0x0;
                        plStack_100 = (longlong *)0x0;
                      }
                      else {
                        plVar10 = (longlong *)FUN_23e8bc2f0(plVar22,_DAT_23ed8f6e0);
                        lVar16 = *plVar22;
                        *plVar22 = lVar16 + -1;
                        if (lVar16 + -1 == 0) {
                          (**(code **)(plVar22[1] + 0x30))(plVar22);
                        }
                        pcStack_108 = _Py_NoneStruct_exref;
                        if (plVar10 == (longlong *)0x0) {
                          plVar10 = *(longlong **)(param_1 + 0x60);
                          pcVar20 = *(code **)(param_1 + 0x68);
                          pcVar24 = *(code **)(param_1 + 0x70);
                          plVar22 = (longlong *)0x0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          uVar25 = 0x11f;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          plStack_e8 = (longlong *)0x0;
                          plStack_e0 = (longlong *)0x0;
                          plStack_d8 = (longlong *)0x0;
                          plStack_f0 = (longlong *)0x0;
                          plStack_100 = (longlong *)0x0;
                          plStack_f8 = (longlong *)0x0;
                        }
                        else {
                          *(undefined4 *)(plVar3 + 5) = 0x11f;
                          plVar22 = (longlong *)FUN_23e91a870(param_1);
                          lVar16 = *plVar10;
                          *plVar10 = lVar16 + -1;
                          if (lVar16 + -1 == 0) {
                            (**(code **)(plVar10[1] + 0x30))(plVar10);
                          }
                          if (plVar22 == (longlong *)0x0) goto LAB_23aabfbfb;
                          iVar8 = FUN_23a35f020(plVar22);
                          if (iVar8 == -1) {
                            pcVar24 = *(code **)(param_1 + 0x70);
                            plVar10 = *(longlong **)(param_1 + 0x60);
                            pcVar20 = *(code **)(param_1 + 0x68);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            pcStack_108 = _Py_NoneStruct_exref;
                            uVar25 = 0x120;
                            plStack_e8 = (longlong *)0x0;
                            plStack_e0 = (longlong *)0x0;
                            plStack_d8 = (longlong *)0x0;
                            plStack_f0 = (longlong *)0x0;
                            plStack_f8 = (longlong *)0x0;
                            plStack_100 = (longlong *)0x0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            goto LAB_23aabe56d;
                          }
                          plStack_100 = (longlong *)0x0;
                          plVar10 = plVar22;
                          if (iVar8 != 0) goto LAB_23aabfb2e;
                          plStack_100 = (longlong *)FUN_23e8bc2f0(plVar11,DAT_23ed6ce40);
                          if (plStack_100 == (longlong *)0x0) {
LAB_23aac06fa:
                            pcStack_108 = _Py_NoneStruct_exref;
                            plVar10 = *(longlong **)(param_1 + 0x60);
                            pcVar20 = *(code **)(param_1 + 0x68);
                            pcVar24 = *(code **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            uVar25 = 0x121;
                            plStack_e8 = (longlong *)0x0;
                            plStack_e0 = (longlong *)0x0;
                            plStack_d8 = (longlong *)0x0;
                            plStack_f0 = (longlong *)0x0;
                            plStack_f8 = (longlong *)0x0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          }
                          else {
                            *(undefined4 *)(plVar3 + 5) = 0x121;
                            plVar23 = (longlong *)FUN_23e9557e0(param_1,plStack_100,_DAT_23ed8f700);
                            lVar16 = *plStack_100;
                            *plStack_100 = lVar16 + -1;
                            if (lVar16 + -1 == 0) {
                              FUN_23a334bc0(plStack_100);
                            }
                            pcStack_108 = _Py_NoneStruct_exref;
                            if (plVar23 == (longlong *)0x0) {
                              plVar10 = *(longlong **)(param_1 + 0x60);
                              pcVar20 = *(code **)(param_1 + 0x68);
                              pcVar24 = *(code **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              uVar25 = 0x121;
                              plStack_e8 = (longlong *)0x0;
                              plStack_e0 = (longlong *)0x0;
                              plStack_d8 = (longlong *)0x0;
                              plStack_f0 = (longlong *)0x0;
                              plStack_100 = (longlong *)0x0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              plStack_f8 = (longlong *)0x0;
                            }
                            else {
                              plVar17 = (longlong *)FUN_23e8bc2f0(plVar23,_DAT_23ed8f6e0);
                              lVar16 = *plVar23;
                              *plVar23 = lVar16 + -1;
                              if (lVar16 + -1 == 0) {
                                FUN_23a334bc0(plVar23);
                              }
                              pcStack_108 = _Py_NoneStruct_exref;
                              if (plVar17 == (longlong *)0x0) {
                                plVar10 = *(longlong **)(param_1 + 0x60);
                                pcVar20 = *(code **)(param_1 + 0x68);
                                pcVar24 = *(code **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                uVar25 = 0x121;
                                plStack_e8 = (longlong *)0x0;
                                plStack_e0 = (longlong *)0x0;
                                plStack_d8 = (longlong *)0x0;
                                plStack_f8 = (longlong *)0x0;
                                plStack_100 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plStack_f0 = (longlong *)0x0;
                              }
                              else {
                                *(undefined4 *)(plVar3 + 5) = 0x121;
                                plStack_100 = (longlong *)FUN_23e91a870(param_1);
                                lVar16 = *plVar17;
                                *plVar17 = lVar16 + -1;
                                if (lVar16 + -1 == 0) {
                                  FUN_23a334bc0(plVar17);
                                }
                                if (plStack_100 == (longlong *)0x0) goto LAB_23aac06fa;
                                iVar8 = FUN_23a35f020(plStack_100);
                                if (iVar8 == -1) {
                                  plVar10 = *(longlong **)(param_1 + 0x60);
                                  pcVar20 = *(code **)(param_1 + 0x68);
                                  pcVar24 = *(code **)(param_1 + 0x70);
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  uVar25 = 0x122;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
LAB_23aac06bc:
                                  plStack_e8 = (longlong *)0x0;
                                  plStack_e0 = (longlong *)0x0;
                                  plStack_d8 = (longlong *)0x0;
                                  plStack_f0 = (longlong *)0x0;
                                  plStack_f8 = (longlong *)0x0;
                                  pcStack_108 = _Py_NoneStruct_exref;
                                  goto LAB_23aabe56d;
                                }
                                if (iVar8 != 0) {
                                  plStack_f8 = (longlong *)FUN_23e8bc2f0(plStack_100,DAT_23ed6d020);
                                  if (plStack_f8 != (longlong *)0x0) {
                                    *(undefined4 *)(plVar3 + 5) = 0x124;
                                    plStack_f0 = (longlong *)FUN_23e94bb80(param_1,plStack_f8);
                                    lVar16 = *plStack_f8;
                                    *plStack_f8 = lVar16 + -1;
                                    if (lVar16 + -1 == 0) {
                                      FUN_23a334bc0(plStack_f8);
                                    }
                                    if (plStack_f0 == (longlong *)0x0) {
LAB_23aac093b:
                                      pcStack_108 = _Py_NoneStruct_exref;
                                      plVar10 = *(longlong **)(param_1 + 0x60);
                                      pcVar20 = *(code **)(param_1 + 0x68);
                                      pcVar24 = *(code **)(param_1 + 0x70);
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      plStack_e8 = (longlong *)0x0;
                                      plStack_e0 = (longlong *)0x0;
                                      plStack_d8 = (longlong *)0x0;
                                      plStack_f8 = (longlong *)0x0;
                                      uVar25 = 0x124;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      goto LAB_23aabe56d;
                                    }
                                    plStack_f8 = (longlong *)
                                                 FUN_23a388650(param_1,plStack_f0,DAT_23ed6ccf0,0);
                                    lVar16 = *plStack_f0;
                                    *plStack_f0 = lVar16 + -1;
                                    if (lVar16 + -1 == 0) {
                                      FUN_23a334bc0();
                                    }
                                    if (plStack_f8 != (longlong *)0x0) {
                                      plStack_f0 = (longlong *)
                                                   FUN_23e8bc2f0(plStack_f8,_DAT_23ed8f6e0);
                                      lVar16 = *plStack_f8;
                                      *plStack_f8 = lVar16 + -1;
                                      if (lVar16 + -1 == 0) {
                                        FUN_23a334bc0(plStack_f8);
                                      }
                                      if (plStack_f0 == (longlong *)0x0) goto LAB_23aac093b;
                                      *(undefined4 *)(plVar3 + 5) = 0x124;
                                      plVar10 = (longlong *)FUN_23e91a870();
                                      lVar16 = *plStack_f0;
                                      *plStack_f0 = lVar16 + -1;
                                      if (lVar16 + -1 == 0) {
                                        FUN_23a334bc0();
                                      }
                                      plStack_f8 = plVar10;
                                      if (plVar10 != (longlong *)0x0) {
                                        *plVar22 = *plVar22 + -1;
                                        if (*plVar22 == 0) {
                                          FUN_23a334bc0(plVar22);
                                        }
                                        goto LAB_23aabfb2e;
                                      }
                                    }
                                  }
                                  pcStack_108 = _Py_NoneStruct_exref;
                                  plVar10 = *(longlong **)(param_1 + 0x60);
                                  pcVar20 = *(code **)(param_1 + 0x68);
                                  pcVar24 = *(code **)(param_1 + 0x70);
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  uVar25 = 0x124;
                                  plStack_e8 = (longlong *)0x0;
                                  plStack_e0 = (longlong *)0x0;
                                  plStack_d8 = (longlong *)0x0;
                                  plStack_f0 = (longlong *)0x0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  goto LAB_23aabe56d;
                                }
LAB_23aabfb2e:
                                iVar8 = FUN_23a35f020(plVar13);
                                plVar22 = plVar10;
                                if (iVar8 == -1) {
LAB_23aac069f:
                                  pcVar24 = *(code **)(param_1 + 0x70);
                                  plVar10 = *(longlong **)(param_1 + 0x60);
                                  pcVar20 = *(code **)(param_1 + 0x68);
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  uVar25 = 0x126;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  goto LAB_23aac06bc;
                                }
                                if (iVar8 == 0) {
LAB_23aabfb47:
                                  lVar14 = FUN_23ebc07d0();
                                  lVar16 = _DAT_23ed8f710;
                                  if (lVar14 == 0) {
                                    FUN_23e915740(param_1,&plStack_78,DAT_23ed8f388);
                                    pcVar24 = pcStack_68;
                                    plVar10 = plStack_78;
                                    pcVar20 = pcStack_70;
                                  }
                                  else {
                                    *(undefined4 *)(plVar3 + 5) = 0x127;
                                    plVar23 = (longlong *)
                                              FUN_23e915840(param_1,lVar14,_DAT_23ed8f6e8,
                                                            *(undefined8 *)(lVar16 + 0x18));
                                    if (plVar23 != (longlong *)0x0) {
                                      lVar16 = *plVar23;
                                      *plVar23 = lVar16 + -1;
                                      if (lVar16 + -1 == 0) {
                                        FUN_23a334bc0(plVar23);
                                      }
                                      lVar16 = *(longlong *)_Py_NoneStruct_exref;
                                      goto LAB_23aabe288;
                                    }
                                    pcVar24 = *(code **)(param_1 + 0x70);
                                    plVar10 = *(longlong **)(param_1 + 0x60);
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    pcVar20 = *(code **)(param_1 + 0x68);
                                  }
                                  plStack_f8 = (longlong *)0x0;
                                  plStack_e8 = (longlong *)0x0;
                                  plStack_e0 = (longlong *)0x0;
                                  plStack_d8 = (longlong *)0x0;
                                  plStack_f0 = (longlong *)0x0;
                                  pcStack_108 = _Py_NoneStruct_exref;
                                  uVar25 = 0x127;
                                  goto LAB_23aabe56d;
                                }
                                uVar9 = FUN_23a35f020(plVar10);
                                pcStack_108 = _Py_NoneStruct_exref;
                                uVar7 = _DAT_23ed8f718;
                                uVar15 = DAT_23ed6ccf0;
                                if (uVar9 == 0xffffffff) goto LAB_23aac069f;
                                if ((uVar9 & 1) == 0) goto LAB_23aabfb47;
                                *(undefined4 *)(plVar3 + 5) = 299;
                                plStack_f8 = (longlong *)
                                             FUN_23e95c160(param_1,uVar7,DAT_23ed8f338,pcStack_108,
                                                           pcStack_108,uVar15);
                                plVar23 = _DAT_23ed8f720;
                                if (plStack_f8 == (longlong *)0x0) {
                                  plVar10 = *(longlong **)(param_1 + 0x60);
                                  pcVar20 = *(code **)(param_1 + 0x68);
                                  pcVar24 = *(code **)(param_1 + 0x70);
                                  plStack_e8 = (longlong *)0x0;
                                  uVar25 = 299;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  plStack_e0 = (longlong *)0x0;
                                  plStack_d8 = (longlong *)0x0;
                                  plStack_f0 = (longlong *)0x0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                }
                                else {
                                  plVar17 = (longlong *)
                                            FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
                                  *plVar23 = *plVar23 + 1;
                                  plVar17[3] = (longlong)plVar23;
                                  lVar16 = FUN_23e94f9d0(param_1,plVar2,DAT_23ed6cd28);
                                  if (lVar16 == 0) {
                                    plVar10 = *(longlong **)(param_1 + 0x60);
                                    pcVar20 = *(code **)(param_1 + 0x68);
                                    pcVar24 = *(code **)(param_1 + 0x70);
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    *plVar17 = *plVar17 + -1;
                                    plStack_f0 = (longlong *)0x0;
                                    if (*plVar17 == 0) {
                                      FUN_23a334bc0(plVar17);
                                      plStack_e8 = (longlong *)0x0;
                                      uVar25 = 0x130;
                                      plStack_e0 = (longlong *)0x0;
                                      plStack_d8 = (longlong *)0x0;
                                    }
                                    else {
                                      uVar25 = 0x130;
                                      plStack_e8 = (longlong *)0x0;
                                      plStack_e0 = (longlong *)0x0;
                                      plStack_d8 = (longlong *)0x0;
                                    }
                                  }
                                  else {
                                    plVar17[4] = lVar16;
                                    plVar23 = _DAT_23ed8f728;
                                    *_DAT_23ed8f728 = *_DAT_23ed8f728 + 1;
                                    plVar17[5] = (longlong)plVar23;
                                    plStack_f0 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar17);
                                    *plVar17 = *plVar17 + -1;
                                    if (*plVar17 == 0) {
                                      FUN_23a334bc0(plVar17);
                                    }
                                    plVar23 = _DAT_23ed8f730;
                                    if (plStack_f0 == (longlong *)0x0) {
                                      plVar10 = *(longlong **)(param_1 + 0x60);
                                      pcVar20 = *(code **)(param_1 + 0x68);
                                      pcVar24 = *(code **)(param_1 + 0x70);
                                      plStack_e8 = (longlong *)0x0;
                                      uVar25 = 0x12f;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      plStack_e0 = (longlong *)0x0;
                                      plStack_d8 = (longlong *)0x0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                    }
                                    else {
                                      plVar17 = (longlong *)
                                                FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
                                      *plVar23 = *plVar23 + 1;
                                      plVar17[3] = (longlong)plVar23;
                                      lVar16 = FUN_23e94f9d0(param_1,plVar13,DAT_23ed6cd28);
                                      if (lVar16 == 0) {
                                        plVar10 = *(longlong **)(param_1 + 0x60);
                                        pcVar20 = *(code **)(param_1 + 0x68);
                                        pcVar24 = *(code **)(param_1 + 0x70);
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        *plVar17 = *plVar17 + -1;
                                        if (*plVar17 == 0) {
                                          FUN_23a334bc0(plVar17);
                                        }
                                        uVar25 = 0x138;
                                        plStack_e8 = (longlong *)0x0;
                                        plStack_e0 = (longlong *)0x0;
                                        plStack_d8 = (longlong *)0x0;
                                      }
                                      else {
                                        plVar17[4] = lVar16;
                                        plVar23 = _DAT_23ed8f738;
                                        *_DAT_23ed8f738 = *_DAT_23ed8f738 + 1;
                                        plVar17[5] = (longlong)plVar23;
                                        plStack_d8 = (longlong *)
                                                     PyUnicode_Join(DAT_23ed6cd28,plVar17);
                                        *plVar17 = *plVar17 + -1;
                                        if (*plVar17 == 0) {
                                          FUN_23a334bc0(plVar17);
                                        }
                                        uVar15 = _DAT_23ed8f740;
                                        if (plStack_d8 == (longlong *)0x0) {
                                          plVar10 = *(longlong **)(param_1 + 0x60);
                                          pcVar20 = *(code **)(param_1 + 0x68);
                                          pcVar24 = *(code **)(param_1 + 0x70);
                                          plStack_e8 = (longlong *)0x0;
                                          uVar25 = 0x138;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          plStack_e0 = (longlong *)0x0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                        }
                                        else {
                                          plStack_e0 = (longlong *)_PyDict_NewPresized(3);
                                          PyDict_SetItem(plStack_e0,uVar15,plVar10);
                                          PyDict_SetItem(plStack_e0,_DAT_23ed8f748,plStack_f0);
                                          PyDict_SetItem(plStack_e0,_DAT_23ed8f750);
                                          plVar23 = (longlong *)
                                                    FUN_23e8bc2f0(plStack_f8,_DAT_23ed8f760);
                                          pcVar24 = _DAT_23ed8f768;
                                          if (plVar23 == (longlong *)0x0) {
                                            plVar10 = *(longlong **)(param_1 + 0x60);
                                            pcVar20 = *(code **)(param_1 + 0x68);
                                            pcVar24 = *(code **)(param_1 + 0x70);
                                            plStack_e8 = (longlong *)0x0;
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            uVar25 = 0x13f;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                          }
                                          else {
                                            *(undefined4 *)(plVar3 + 5) = 0x13f;
                                            auStack_98._0_8_ = plStack_d8;
                                            pcStack_70 = pcVar24;
                                            plStack_78 = plStack_e0;
                                            plStack_e8 = (longlong *)
                                                         FUN_23e939900(param_1,plVar23,auStack_98,
                                                                       &plStack_78,_DAT_23ed8f770);
                                            *plVar23 = *plVar23 + -1;
                                            if (*plVar23 == 0) {
                                              FUN_23a334bc0();
                                            }
                                            if (plStack_e8 == (longlong *)0x0) {
                                              plVar10 = *(longlong **)(param_1 + 0x60);
                                              pcVar20 = *(code **)(param_1 + 0x68);
                                              pcVar24 = *(code **)(param_1 + 0x70);
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              uVar25 = 0x13f;
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                            }
                                            else {
                                              plVar23 = (longlong *)FUN_23e8bc2f0(plStack_e8);
                                              if (plVar23 != (longlong *)0x0) {
                                                iVar8 = FUN_23e97a530(plVar23);
                                                *plVar23 = *plVar23 + -1;
                                                if (*plVar23 == 0) {
                                                  FUN_23a334bc0(plVar23);
                                                }
                                                if (iVar8 != -1) {
                                                  if (iVar8 == 1) {
                                                    lVar16 = FUN_23ebc07d0();
                                                    if (lVar16 == 0) {
                                                      FUN_23e915740(param_1,&plStack_78,
                                                                    DAT_23ed8f388);
                                                      uVar25 = 0x141;
                                                      pcVar24 = pcStack_68;
                                                      plVar10 = plStack_78;
                                                      pcVar20 = pcStack_70;
                                                    }
                                                    else {
                                                      plVar17 = (longlong *)
                                                                FUN_23e8bc2f0(lVar16,DAT_23ed8f390);
                                                      plVar23 = _DAT_23ed8f788;
                                                      if (plVar17 == (longlong *)0x0) {
LAB_23aac0d1b:
                                                        plVar10 = *(longlong **)(param_1 + 0x60);
                                                        pcVar24 = *(code **)(param_1 + 0x70);
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        uVar25 = 0x141;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        pcVar20 = *(code **)(param_1 + 0x68);
                                                      }
                                                      else {
                                                        plVar18 = (longlong *)
                                                                  FUN_23e916ad0(*(undefined8 *)
                                                                                 (param_1 + 0x10),2)
                                                        ;
                                                        *plVar23 = *plVar23 + 1;
                                                        plVar18[3] = (longlong)plVar23;
                                                        lVar16 = FUN_23e94f9d0(param_1,plVar10,
                                                                               DAT_23ed6cd28);
                                                        if (lVar16 == 0) {
                                                          plVar10 = *(longlong **)(param_1 + 0x60);
                                                          pcVar20 = *(code **)(param_1 + 0x68);
                                                          pcVar24 = *(code **)(param_1 + 0x70);
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          *plVar17 = *plVar17 + -1;
                                                          if (*plVar17 == 0) {
                                                            FUN_23a334bc0(plVar17);
                                                          }
                                                          *plVar18 = *plVar18 + -1;
                                                          uVar25 = 0x141;
                                                          if (*plVar18 == 0) {
                                                            FUN_23a334bc0(plVar18);
                                                            uVar25 = 0x141;
                                                          }
                                                        }
                                                        else {
                                                          plVar18[4] = lVar16;
                                                          plVar23 = (longlong *)
                                                                    PyUnicode_Join(DAT_23ed6cd28,
                                                                                   plVar18);
                                                          *plVar18 = *plVar18 + -1;
                                                          if (*plVar18 == 0) {
                                                            FUN_23a334bc0(plVar18);
                                                          }
                                                          if (plVar23 != (longlong *)0x0) {
                                                            *(undefined4 *)(plVar3 + 5) = 0x141;
                                                            plVar18 = (longlong *)
                                                                      FUN_23e914090(param_1,plVar17,
                                                                                    plVar23);
                                                            *plVar17 = *plVar17 + -1;
                                                            if (*plVar17 == 0) {
                                                              FUN_23a334bc0(plVar17);
                                                            }
                                                            *plVar23 = *plVar23 + -1;
                                                            if (*plVar23 == 0) {
                                                              FUN_23a334bc0(plVar23);
                                                            }
                                                            if (plVar18 == (longlong *)0x0)
                                                            goto LAB_23aac0d1b;
LAB_23aac0688:
                                                            *plVar18 = *plVar18 + -1;
                                                            if (*plVar18 == 0) {
                                                              FUN_23a334bc0(plVar18);
                                                            }
LAB_23aabeb16:
                                                            lVar16 = *(longlong *)
                                                                      (*(longlong *)(param_1 + 0x38)
                                                                      + 8);
                                                            plVar3 = *(longlong **)(lVar16 + 0x28);
                                                            plVar22 = (longlong *)plVar3[2];
                                                            *(undefined8 *)
                                                             (*(longlong *)(param_1 + 0x38) + 8) =
                                                                 *(undefined8 *)(lVar16 + 0x30);
                                                            *(undefined4 *)(plVar3 + 8) = 0xffffffff
                                                            ;
                                                            if (plVar22 != (longlong *)0x0) {
                                                              plVar3[2] = 0;
                                                              *plVar22 = *plVar22 + -1;
                                                              if (*plVar22 == 0) {
                                                                (**(code **)(plVar22[1] + 0x30))();
                                                              }
                                                            }
                                                            *plVar3 = *plVar3 + -1;
                                                            if (*plVar3 == 0) {
                                                              (**(code **)(plVar3[1] + 0x30))
                                                                        (plVar3);
                                                            }
                                                            plVar3[0xf] = 0;
                                                            *(longlong *)pcStack_108 =
                                                                 *(longlong *)pcStack_108 + 1;
                                                            if ((plVar11 != (longlong *)0x0) &&
                                                               (*plVar11 = *plVar11 + -1,
                                                               *plVar11 == 0)) {
                                                              (**(code **)(plVar11[1] + 0x30))
                                                                        (plVar11);
                                                            }
                                                            if (plVar12 != (longlong *)0x0)
                                                            goto LAB_23aabe340;
                                                            goto LAB_23aabe350;
                                                          }
                                                          plVar10 = *(longlong **)(param_1 + 0x60);
                                                          pcVar20 = *(code **)(param_1 + 0x68);
                                                          pcVar24 = *(code **)(param_1 + 0x70);
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          uVar25 = 0x141;
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          *plVar17 = *plVar17 + -1;
                                                          if (*plVar17 == 0) {
                                                            FUN_23a334bc0(plVar17);
                                                            uVar25 = 0x141;
                                                          }
                                                        }
                                                      }
                                                    }
                                                  }
                                                  else {
                                                    lVar16 = FUN_23ebc07d0();
                                                    if (lVar16 == 0) {
                                                      FUN_23e915740(param_1,&plStack_78,
                                                                    DAT_23ed8f388);
                                                      uVar25 = 0x143;
                                                      pcVar24 = pcStack_68;
                                                      plVar10 = plStack_78;
                                                      pcVar20 = pcStack_70;
                                                    }
                                                    else {
                                                      plVar17 = (longlong *)
                                                                FUN_23e8bc2f0(lVar16,DAT_23ed8f450);
                                                      plVar23 = _DAT_23ed8f790;
                                                      if (plVar17 == (longlong *)0x0) {
LAB_23aac0b9f:
                                                        plVar10 = *(longlong **)(param_1 + 0x60);
                                                        pcVar24 = *(code **)(param_1 + 0x70);
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        pcVar20 = *(code **)(param_1 + 0x68);
                                                        uVar25 = 0x143;
                                                      }
                                                      else {
                                                        plVar18 = (longlong *)
                                                                  FUN_23e916ad0(*(undefined8 *)
                                                                                 (param_1 + 0x10),4)
                                                        ;
                                                        *plVar23 = *plVar23 + 1;
                                                        uVar15 = _DAT_23ed8f778;
                                                        plVar18[3] = (longlong)plVar23;
                                                        plVar23 = (longlong *)
                                                                  FUN_23e8bc2f0(plStack_e8,uVar15);
                                                        if (plVar23 == (longlong *)0x0) {
LAB_23aac0ae6:
                                                          pcVar24 = *(code **)(param_1 + 0x70);
                                                          plVar10 = *(longlong **)(param_1 + 0x60);
                                                          pcVar20 = *(code **)(param_1 + 0x68);
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          lVar16 = *plVar17;
                                                          *plVar17 = lVar16 + -1;
                                                          if (lVar16 + -1 == 0) {
                                                            FUN_23a334bc0(plVar17);
                                                          }
                                                        }
                                                        else {
                                                          lVar16 = FUN_23e94f9d0(param_1,plVar23,
                                                                                 DAT_23ed6cd28);
                                                          *plVar23 = *plVar23 + -1;
                                                          if (*plVar23 == 0) {
                                                            FUN_23a334bc0(plVar23);
                                                          }
                                                          plVar23 = _DAT_23ed8f798;
                                                          if (lVar16 == 0) goto LAB_23aac0ae6;
                                                          plVar18[4] = lVar16;
                                                          *plVar23 = *plVar23 + 1;
                                                          plVar18[5] = (longlong)plVar23;
                                                          plVar23 = (longlong *)
                                                                    FUN_23e8bc2f0(plStack_e8,
                                                                                  _DAT_23ed8f748);
                                                          if (plVar23 == (longlong *)0x0)
                                                          goto LAB_23aac0ae6;
                                                          lVar16 = FUN_23e94f9d0(param_1,plVar23,
                                                                                 DAT_23ed6cd28);
                                                          *plVar23 = *plVar23 + -1;
                                                          if (*plVar23 == 0) {
                                                            FUN_23a334bc0(plVar23);
                                                          }
                                                          if (lVar16 == 0) goto LAB_23aac0ae6;
                                                          plVar18[6] = lVar16;
                                                          plVar23 = (longlong *)
                                                                    PyUnicode_Join(DAT_23ed6cd28);
                                                          lVar16 = *plVar18;
                                                          *plVar18 = lVar16 + -1;
                                                          if (lVar16 + -1 == 0) {
                                                            FUN_23a334bc0(plVar18);
                                                          }
                                                          if (plVar23 != (longlong *)0x0) {
                                                            *(undefined4 *)(plVar3 + 5) = 0x143;
                                                            plVar18 = (longlong *)
                                                                      FUN_23e914090(param_1,plVar17,
                                                                                    plVar23);
                                                            lVar16 = *plVar17;
                                                            *plVar17 = lVar16 + -1;
                                                            if (lVar16 + -1 == 0) {
                                                              FUN_23a334bc0(plVar17);
                                                            }
                                                            *plVar23 = *plVar23 + -1;
                                                            if (*plVar23 == 0) {
                                                              FUN_23a334bc0(plVar23);
                                                            }
                                                            if (plVar18 != (longlong *)0x0)
                                                            goto LAB_23aac0688;
                                                            goto LAB_23aac0b9f;
                                                          }
                                                          pcVar24 = *(code **)(param_1 + 0x70);
                                                          plVar10 = *(longlong **)(param_1 + 0x60);
                                                          pcVar20 = *(code **)(param_1 + 0x68);
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          plVar18 = plVar17;
                                                        }
                                                        lVar16 = *plVar18;
                                                        *plVar18 = lVar16 + -1;
                                                        uVar25 = 0x143;
                                                        if (lVar16 + -1 == 0) {
                                                          FUN_23a334bc0(plVar18);
                                                          pcStack_c8._0_4_ = 0x143;
                                                          uVar25 = pcStack_c8._0_4_;
                                                        }
                                                      }
                                                    }
                                                  }
                                                  goto LAB_23aabe56d;
                                                }
                                              }
                                              plVar10 = *(longlong **)(param_1 + 0x60);
                                              pcVar20 = *(code **)(param_1 + 0x68);
                                              pcVar24 = *(code **)(param_1 + 0x70);
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              uVar25 = 0x140;
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                  else {
                    lVar14 = FUN_23ebc07d0();
                    lVar16 = _DAT_23ed8f6f0;
                    if (lVar14 == 0) {
                      FUN_23e915740(param_1,&plStack_78,DAT_23ed8f388);
                      pcVar24 = pcStack_68;
                      plVar10 = plStack_78;
                      pcVar20 = pcStack_70;
                    }
                    else {
                      *(undefined4 *)(plVar3 + 5) = 0x11b;
                      plVar10 = (longlong *)
                                FUN_23e915840(param_1,lVar14,_DAT_23ed8f6e8,
                                              *(undefined8 *)(lVar16 + 0x18));
                      if (plVar10 != (longlong *)0x0) {
                        *plVar10 = *plVar10 + -1;
                        if (*plVar10 == 0) {
                          (**(code **)(plVar10[1] + 0x30))(plVar10);
                        }
                        plVar10 = (longlong *)0x0;
                        plStack_100 = (longlong *)0x0;
                        lVar16 = *(longlong *)_Py_NoneStruct_exref;
LAB_23aabe288:
                        pcStack_108 = _Py_NoneStruct_exref;
                        *(longlong *)_Py_NoneStruct_exref = lVar16 + 1;
                        lVar16 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                        plVar3 = *(longlong **)(lVar16 + 0x28);
                        plVar22 = (longlong *)plVar3[2];
                        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                             *(undefined8 *)(lVar16 + 0x30);
                        *(undefined4 *)(plVar3 + 8) = 0xffffffff;
                        if (plVar22 != (longlong *)0x0) {
                          plVar3[2] = 0;
                          *plVar22 = *plVar22 + -1;
                          if (*plVar22 == 0) {
                            (**(code **)(plVar22[1] + 0x30))();
                          }
                        }
                        *plVar3 = *plVar3 + -1;
                        if (*plVar3 == 0) {
                          (**(code **)(plVar3[1] + 0x30))(plVar3);
                        }
                        plVar3[0xf] = 0;
                        *plVar11 = *plVar11 + -1;
                        if (*plVar11 == 0) {
                          (**(code **)(plVar11[1] + 0x30))(plVar11);
                          plStack_e8 = (longlong *)0x0;
                          plStack_e0 = (longlong *)0x0;
                          plStack_d8 = (longlong *)0x0;
                          plStack_f0 = (longlong *)0x0;
                          plStack_f8 = (longlong *)0x0;
LAB_23aabe340:
                          *plVar12 = *plVar12 + -1;
                          if (*plVar12 == 0) {
LAB_23aabe346:
                            (**(code **)(plVar12[1] + 0x30))(plVar12);
                          }
LAB_23aabe350:
                          if (plVar13 == (longlong *)0x0) goto LAB_23aabe360;
                        }
                        else {
                          *plVar12 = *plVar12 + -1;
                          if (*plVar12 == 0) {
                            plStack_e0 = (longlong *)0x0;
                            plStack_e8 = (longlong *)0x0;
                            plStack_d8 = (longlong *)0x0;
                            plStack_f0 = (longlong *)0x0;
                            plStack_f8 = (longlong *)0x0;
                            goto LAB_23aabe346;
                          }
                          plStack_e8 = (longlong *)0x0;
                          plStack_d8 = (longlong *)0x0;
                          plStack_f8 = (longlong *)0x0;
                          plStack_f0 = (longlong *)0x0;
                          plStack_e0 = (longlong *)0x0;
                        }
                        *plVar13 = *plVar13 + -1;
                        if (*plVar13 == 0) {
                          (**(code **)(plVar13[1] + 0x30))(plVar13);
                        }
LAB_23aabe360:
                        if ((plVar10 != (longlong *)0x0) &&
                           (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
                          (**(code **)(plVar10[1] + 0x30))(plVar10);
                        }
                        if ((plStack_100 != (longlong *)0x0) &&
                           (lVar16 = *plStack_100, *plStack_100 = lVar16 + -1, lVar16 + -1 == 0)) {
                          (**(code **)(plStack_100[1] + 0x30))(plStack_100);
                        }
                        if ((plStack_f8 != (longlong *)0x0) &&
                           (lVar16 = *plStack_f8, *plStack_f8 = lVar16 + -1, lVar16 + -1 == 0)) {
                          (**(code **)(plStack_f8[1] + 0x30))(plStack_f8);
                        }
                        if ((plStack_f0 != (longlong *)0x0) &&
                           (lVar16 = *plStack_f0, *plStack_f0 = lVar16 + -1, lVar16 + -1 == 0)) {
                          (**(code **)(plStack_f0[1] + 0x30))(plStack_f0);
                        }
                        if ((plStack_d8 != (longlong *)0x0) &&
                           (lVar16 = *plStack_d8, *plStack_d8 = lVar16 + -1, lVar16 + -1 == 0)) {
                          (**(code **)(plStack_d8[1] + 0x30))(plStack_d8);
                        }
                        if ((plStack_e0 != (longlong *)0x0) &&
                           (lVar16 = *plStack_e0, *plStack_e0 = lVar16 + -1, lVar16 + -1 == 0)) {
                          (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
                        }
                        if ((plStack_e8 != (longlong *)0x0) &&
                           (lVar16 = *plStack_e8, *plStack_e8 = lVar16 + -1, lVar16 + -1 == 0)) {
                          (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
                        }
                        lVar16 = *plVar1;
                        *plVar1 = lVar16 + -1;
                        if (lVar16 + -1 == 0) {
                          (**(code **)(plVar1[1] + 0x30))(plVar1);
                        }
                        lVar16 = *plVar2;
                        *plVar2 = lVar16 + -1;
                        if (lVar16 + -1 != 0) {
                          return pcStack_108;
                        }
                        (**(code **)(plVar2[1] + 0x30))(plVar2);
                        return pcStack_108;
                      }
                      pcVar24 = *(code **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      plVar10 = *(longlong **)(param_1 + 0x60);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      pcVar20 = *(code **)(param_1 + 0x68);
                    }
                    pcStack_108 = _Py_NoneStruct_exref;
                    plStack_e8 = (longlong *)0x0;
                    plStack_e0 = (longlong *)0x0;
                    plStack_d8 = (longlong *)0x0;
                    plStack_f0 = (longlong *)0x0;
                    plStack_f8 = (longlong *)0x0;
                    plStack_100 = (longlong *)0x0;
                    plVar22 = (longlong *)0x0;
                    uVar25 = 0x11b;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_23aabe56d:
  plVar23 = *(longlong **)(param_1 + 0x138);
  auStack_98._8_8_ = pcVar20;
  auStack_98._0_8_ = plVar10;
  if (plVar23 != (longlong *)0x0) {
    *plVar23 = *plVar23 + 1;
  }
  pcVar20 = DAT_23ed6a4f8;
  apcStack_88[0] = pcVar24;
  if (pcVar24 == (code *)0x0) {
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar20 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar24 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar24;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcStack_c8 = _PyRuntime_exref;
    *(longlong **)(pcVar20 + 0x18) = plVar3;
    *(longlong *)(pcVar20 + 0x10) = 0;
    *plVar3 = *plVar3 + 1;
    lVar16 = *(longlong *)(pcStack_c8 + 0x1f8);
    *(undefined4 *)(pcVar20 + 0x24) = uVar25;
    *(undefined4 *)(pcVar20 + 0x20) = 0xffffffff;
    lVar16 = *(longlong *)(*(longlong *)(lVar16 + 0x10) + 0x2e8);
    lVar14 = *(longlong *)(pcVar20 + -8);
    puVar4 = *(undefined8 **)(lVar16 + 8);
    *puVar4 = pcVar20 + -0x10;
    *(longlong *)(pcVar20 + -0x10) = lVar16;
    *(ulonglong *)(pcVar20 + -8) = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar4;
    *(code **)(lVar16 + 8) = pcVar20 + -0x10;
    if ((apcStack_88[0] != (code *)0x0) &&
       (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
       *(longlong *)apcStack_88[0] == 0)) {
      (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))(apcStack_88[0]);
    }
  }
  else {
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar20 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar21 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar21;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcStack_c8 = _PyRuntime_exref;
    *(longlong **)(pcVar20 + 0x18) = plVar3;
    *plVar3 = *plVar3 + 1;
    lVar16 = *(longlong *)(pcStack_c8 + 0x1f8);
    *(undefined4 *)(pcVar20 + 0x24) = uVar25;
    *(undefined4 *)(pcVar20 + 0x20) = 0xffffffff;
    lVar16 = *(longlong *)(*(longlong *)(lVar16 + 0x10) + 0x2e8);
    lVar14 = *(longlong *)(pcVar20 + -8);
    puVar4 = *(undefined8 **)(lVar16 + 8);
    *puVar4 = pcVar20 + -0x10;
    *(longlong *)(pcVar20 + -0x10) = lVar16;
    *(ulonglong *)(pcVar20 + -8) = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar4;
    *(code **)(lVar16 + 8) = pcVar20 + -0x10;
    *(code **)(pcVar20 + 0x10) = pcVar24;
    *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
    if ((apcStack_88[0] != (code *)0x0) &&
       (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
       *(longlong *)apcStack_88[0] == 0)) {
      (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
    }
  }
  apcStack_88[0] = pcVar20;
  if (((code *)auStack_98._0_8_ != (code *)0x0) && ((code *)auStack_98._0_8_ != pcStack_108)) {
    FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,apcStack_88);
  }
  plVar10 = *(longlong **)(auStack_98._8_8_ + 0x28);
  if (apcStack_88[0] == pcStack_108) {
    pcVar24 = (code *)0x0;
  }
  else {
    pcVar24 = apcStack_88[0];
    if (apcStack_88[0] != (code *)0x0) {
      *(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + 1;
    }
  }
  *(code **)(auStack_98._8_8_ + 0x28) = pcVar24;
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))();
  }
  plVar10 = *(longlong **)(param_1 + 0x138);
  *(undefined8 *)(param_1 + 0x138) = auStack_98._8_8_;
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))();
  }
  *(longlong *)auStack_98._0_8_ = *(longlong *)auStack_98._0_8_ + -1;
  if (*(longlong *)auStack_98._0_8_ == 0) {
    (**(code **)(*(longlong *)(auStack_98._0_8_ + 8) + 0x30))();
  }
  if ((apcStack_88[0] != (code *)0x0) &&
     (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
     *(longlong *)apcStack_88[0] == 0)) {
    (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
  }
  pcVar20 = *(code **)(param_1 + 0x138);
  apcStack_88[0] = (code *)0x0;
  auStack_98 = (undefined1  [16])0x0;
  pcVar24 = *(code **)PyExc_Exception_exref;
  pcVar21 = *(code **)(pcVar20 + 8);
  if ((*(uint *)(*(longlong *)(pcVar24 + 8) + 0xa8) & 0x4000000) == 0) {
    if ((-1 < (int)*(uint *)(*(longlong *)(pcVar24 + 8) + 0xa8)) ||
       (((byte)pcVar24[0xab] & 0x40) == 0)) {
LAB_23aabe890:
      plVar10 = *(longlong **)PyExc_TypeError_exref;
      uVar15 = PyUnicode_FromString
                         ("catching classes that do not inherit from BaseException is not allowed");
      plVar17 = *(longlong **)(param_1 + 0x60);
      plVar18 = *(longlong **)(param_1 + 0x68);
      plVar19 = *(longlong **)(param_1 + 0x70);
      *(longlong **)(param_1 + 0x60) = plVar10;
      *plVar10 = *plVar10 + 1;
      *(undefined8 *)(param_1 + 0x68) = uVar15;
      *(undefined8 *)(param_1 + 0x70) = 0;
      if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
        (**(code **)(plVar17[1] + 0x30))();
      }
      if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
        (**(code **)(plVar18[1] + 0x30))(plVar18);
      }
      if ((plVar19 == (longlong *)0x0) || (*plVar19 = *plVar19 + -1, *plVar19 != 0)) {
LAB_23aabe905:
        pcVar20 = *(code **)(param_1 + 0x138);
      }
      else {
        (**(code **)(plVar19[1] + 0x30))(plVar19);
        pcVar20 = *(code **)(param_1 + 0x138);
      }
LAB_23aabe90c:
      *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
      lVar16 = FUN_23ebc07d0();
      if (lVar16 == 0) {
        FUN_23e915740(param_1,&plStack_78,DAT_23ed8f388);
        pcStack_108 = (code *)plStack_78;
        pcStack_b8 = pcStack_70;
        pcVar24 = pcStack_68;
      }
      else {
        plVar17 = (longlong *)FUN_23e8bc2f0(lVar16,DAT_23ed8f3c0);
        plVar10 = _DAT_23ed8f790;
        if (plVar17 == (longlong *)0x0) {
LAB_23aabf400:
          pcStack_108 = *(code **)(param_1 + 0x60);
          pcVar24 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcStack_b8 = *(code **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23aabf42c;
        }
        lVar16 = *(longlong *)(param_1 + 0x10);
        plVar18 = *(longlong **)(lVar16 + 0xe20);
        if (plVar18 == (longlong *)0x0) {
          plVar18 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
        }
        else {
          lVar14 = plVar18[3];
          *(int *)(lVar16 + 0xebc) = *(int *)(lVar16 + 0xebc) + -1;
          *(longlong *)(lVar16 + 0xe20) = lVar14;
          *plVar18 = 1;
        }
        plVar18[4] = 0;
        lVar16 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_c8 + 0x1f8) + 0x10) + 0x2e8);
        lVar14 = plVar18[-1];
        pcVar21 = *(code **)(lVar16 + 8);
        *(longlong **)pcVar21 = plVar18 + -2;
        plVar18[-2] = lVar16;
        plVar18[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)pcVar21;
        *(longlong **)(lVar16 + 8) = plVar18 + -2;
        plVar19 = DAT_23ed6a4c0;
        *plVar10 = *plVar10 + 1;
        plVar18[3] = (longlong)plVar10;
        uVar15 = DAT_23ed6cd28;
        pcVar24 = (code *)&DAT_23ed6cce0;
        if (plVar19 == (longlong *)0x0) {
          plVar19 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          if (plVar19 != (longlong *)0x0) {
            *plVar19 = *plVar19 + 1;
            DAT_23ed6a4c0 = plVar19;
            goto LAB_23aabe9e9;
          }
          PyErr_PrintEx(0);
          Py_Exit(1);
LAB_23aabebe2:
          lVar16 = *(longlong *)(pcVar21 + 0x158);
          if (lVar16 != 0) {
            if (*(longlong *)(lVar16 + 0x10) < 1) goto LAB_23aabe808;
            lVar14 = 0;
            while (pcVar24 != *(code **)(lVar16 + 0x18 + lVar14 * 8)) {
              lVar14 = lVar14 + 1;
              if (*(longlong *)(lVar16 + 0x10) == lVar14) goto LAB_23aabe808;
            }
            goto LAB_23aabe90c;
          }
          do {
            if (pcVar24 == pcVar21) goto LAB_23aabe90c;
            pcVar21 = *(code **)(pcVar21 + 0x100);
          } while (pcVar21 != (code *)0x0);
          if (pcVar24 == PyBaseObject_Type_exref) goto LAB_23aabe90c;
          goto LAB_23aabe808;
        }
LAB_23aabe9e9:
        uStack_a0 = uVar15;
        pcStack_a8 = pcVar20;
        lVar16 = FUN_23e94ed00(param_1,plVar19,&pcStack_a8);
        if (lVar16 != 0) {
          plVar18[4] = lVar16;
          plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar18);
          *plVar18 = *plVar18 + -1;
          if (*plVar18 == 0) {
            (**(code **)(plVar18[1] + 0x30))(plVar18);
          }
          if (plVar10 == (longlong *)0x0) {
            pcStack_108 = *(code **)(param_1 + 0x60);
            pcVar24 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcStack_b8 = *(code **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar17 = *plVar17 + -1;
            if (*plVar17 == 0) {
              (**(code **)(plVar17[1] + 0x30))(plVar17);
            }
            goto LAB_23aabf42c;
          }
          *(undefined4 *)(plVar3 + 5) = 0x146;
          plVar18 = (longlong *)FUN_23e914090(param_1,plVar17,plVar10);
          *plVar17 = *plVar17 + -1;
          if (*plVar17 == 0) {
            (**(code **)(plVar17[1] + 0x30))(plVar17);
          }
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          if (plVar18 == (longlong *)0x0) goto LAB_23aabf400;
          *plVar18 = *plVar18 + -1;
          if (*plVar18 == 0) {
            (**(code **)(plVar18[1] + 0x30))(plVar18);
          }
          *(longlong *)pcVar20 = *(longlong *)pcVar20 + -1;
          if (*(longlong *)pcVar20 == 0) {
            (**(code **)(*(longlong *)(pcVar20 + 8) + 0x30))(pcVar20);
          }
          plVar3 = *(longlong **)(param_1 + 0x138);
          *(longlong **)(param_1 + 0x138) = plVar23;
          plVar10 = plVar22;
          if ((plVar3 != (longlong *)0x0) && (*plVar3 = *plVar3 + -1, *plVar3 == 0)) {
            (**(code **)(plVar3[1] + 0x30))();
          }
          goto LAB_23aabeb16;
        }
        pcStack_108 = *(code **)(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_b8 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar17 = *plVar17 + -1;
        if (*plVar17 == 0) {
          (**(code **)(plVar17[1] + 0x30))(plVar17);
        }
        *plVar18 = *plVar18 + -1;
        if (*plVar18 == 0) {
          (**(code **)(plVar18[1] + 0x30))(plVar18);
        }
      }
LAB_23aabf42c:
      *(longlong *)pcVar20 = *(longlong *)pcVar20 + -1;
      if (*(longlong *)pcVar20 == 0) {
        (**(code **)(*(longlong *)(pcVar20 + 8) + 0x30))(pcVar20);
      }
      plVar10 = *(longlong **)(param_1 + 0x138);
      *(longlong **)(param_1 + 0x138) = plVar23;
      if (plVar10 == (longlong *)0x0) {
        if (pcVar24 != (code *)0x0) {
          plVar10 = *(longlong **)(pcVar24 + 0x18);
joined_r0x00023aabf5d6:
          pcVar20 = pcVar24;
          if (plVar3 != plVar10) goto LAB_23aabf479;
          goto LAB_23aabf060;
        }
      }
      else {
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))();
          if (pcVar24 != (code *)0x0) {
            iVar8 = 0x146;
            goto LAB_23aabf545;
          }
        }
        else if (pcVar24 != (code *)0x0) {
          plVar10 = *(longlong **)(pcVar24 + 0x18);
          goto joined_r0x00023aabf5d6;
        }
      }
      iVar8 = 0x146;
      goto LAB_23aabefc4;
    }
    pcVar5 = *(code **)(pcVar21 + 8);
    if ((*(uint *)(pcVar5 + 0xa8) & 0x40000000) == 0) {
      if (((int)*(uint *)(pcVar5 + 0xa8) < 0) && (((byte)pcVar21[0xab] & 0x40) != 0))
      goto LAB_23aabebe2;
    }
    else {
      pcVar21 = pcVar5;
      if (*(int *)(*(longlong *)(pcVar5 + 8) + 0xa8) < 0) goto LAB_23aabebe2;
    }
    if (pcVar24 == pcVar21) goto LAB_23aabe90c;
  }
  else {
    lVar16 = *(longlong *)(pcVar24 + 0x10);
    if (0 < lVar16) {
      lVar14 = 0;
      do {
        if ((-1 < *(int *)(*(longlong *)(*(longlong *)(pcVar24 + lVar14 * 8 + 0x18) + 8) + 0xa8)) ||
           ((*(byte *)(*(longlong *)(pcVar24 + lVar14 * 8 + 0x18) + 0xab) & 0x40) == 0))
        goto LAB_23aabe890;
        lVar14 = lVar14 + 1;
      } while (lVar16 != lVar14);
      lVar14 = 0;
      do {
        iVar8 = FUN_23a35ebd0(param_1,pcVar21,*(undefined8 *)(pcVar24 + lVar14 * 8 + 0x18));
        if (iVar8 != 0) goto LAB_23aabe905;
        lVar14 = lVar14 + 1;
      } while (lVar16 != lVar14);
      pcVar20 = *(code **)(param_1 + 0x138);
    }
  }
LAB_23aabe808:
  if ((pcVar20 == pcStack_108) || (pcVar20 == (code *)0x0)) {
    pcStack_108 = *(code **)PyExc_RuntimeError_exref;
    pcStack_b8 = (code *)PyUnicode_FromString("No active exception to reraise");
    *(longlong *)pcStack_108 = *(longlong *)pcStack_108 + 1;
    pcVar20 = *(code **)(param_1 + 0x138);
    iVar8 = 0x111;
    *(longlong **)(param_1 + 0x138) = plVar23;
    if ((pcVar20 != (code *)0x0) &&
       (*(longlong *)pcVar20 = *(longlong *)pcVar20 + -1, *(longlong *)pcVar20 == 0)) {
LAB_23aabf80a:
      (**(code **)(*(longlong *)(pcVar20 + 8) + 0x30))(pcVar20);
      if (iVar8 == 0) goto LAB_23aabefb9;
    }
  }
  else {
    pcStack_108 = *(code **)(pcVar20 + 8);
    pcVar24 = *(code **)(pcVar20 + 0x28);
    *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
    *(longlong *)pcStack_108 = *(longlong *)pcStack_108 + 1;
    pcStack_b8 = pcVar20;
    if (pcVar24 != (code *)0x0) {
      *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
      if (plVar3 == *(longlong **)(pcVar24 + 0x18)) {
        *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar24 + 0x24);
      }
      *(longlong **)(param_1 + 0x138) = plVar23;
      *(longlong *)pcVar20 = *(longlong *)pcVar20 + -1;
      if (*(longlong *)pcVar20 == 0) {
        (**(code **)((longlong)pcStack_108 + 0x30))(pcVar20);
        iVar8 = 0;
LAB_23aabf545:
        pcVar20 = pcVar24;
        if (plVar3 == *(longlong **)(pcVar24 + 0x18)) goto LAB_23aabf060;
        if (iVar8 == 0) goto LAB_23aabf558;
LAB_23aabf479:
        uVar25 = 0x146;
      }
      else {
        pcVar20 = pcVar24;
        if (plVar3 == *(longlong **)(pcVar24 + 0x18)) goto LAB_23aabf060;
LAB_23aabf558:
        uVar25 = (undefined4)plVar3[5];
      }
      pcVar20 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar20 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar21 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar21;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong **)(pcVar20 + 0x18) = plVar3;
      *plVar3 = *plVar3 + 1;
      lVar16 = *(longlong *)(pcStack_c8 + 0x1f8);
      *(undefined4 *)(pcVar20 + 0x24) = uVar25;
      *(undefined4 *)(pcVar20 + 0x20) = 0xffffffff;
      lVar16 = *(longlong *)(*(longlong *)(lVar16 + 0x10) + 0x2e8);
      lVar14 = *(longlong *)(pcVar20 + -8);
      puVar4 = *(undefined8 **)(lVar16 + 8);
      *puVar4 = pcVar20 + -0x10;
      *(longlong *)(pcVar20 + -0x10) = lVar16;
      *(ulonglong *)(pcVar20 + -8) = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar4;
      lVar14 = *(longlong *)pcVar24;
      *(code **)(lVar16 + 8) = pcVar20 + -0x10;
      *(code **)(pcVar20 + 0x10) = pcVar24;
      if (lVar14 == 0) {
        (**(code **)(*(longlong *)(pcVar24 + 8) + 0x30))(pcVar24);
      }
      goto LAB_23aabf060;
    }
    *(longlong **)(param_1 + 0x138) = plVar23;
    *(longlong *)pcVar20 = *(longlong *)pcVar20 + -1;
    if (*(longlong *)pcVar20 == 0) {
      iVar8 = 0;
      goto LAB_23aabf80a;
    }
LAB_23aabefb9:
    iVar8 = (int)plVar3[5];
  }
LAB_23aabefc4:
  pcVar20 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar20 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar24 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar24;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  *(longlong **)(pcVar20 + 0x18) = plVar3;
  *(longlong *)(pcVar20 + 0x10) = 0;
  *plVar3 = *plVar3 + 1;
  lVar16 = *(longlong *)(pcStack_c8 + 0x1f8);
  *(int *)(pcVar20 + 0x24) = iVar8;
  *(undefined4 *)(pcVar20 + 0x20) = 0xffffffff;
  lVar16 = *(longlong *)(*(longlong *)(lVar16 + 0x10) + 0x2e8);
  lVar14 = *(longlong *)(pcVar20 + -8);
  puVar4 = *(undefined8 **)(lVar16 + 8);
  *puVar4 = pcVar20 + -0x10;
  *(longlong *)(pcVar20 + -0x10) = lVar16;
  *(ulonglong *)(pcVar20 + -8) = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar4;
  *(code **)(lVar16 + 8) = pcVar20 + -0x10;
LAB_23aabf060:
  FUN_23e8bba40(plVar3,"ooooooooooooo",plVar1,plVar2,plVar11,plVar12,plVar13,plVar22,plStack_100,
                plStack_f8,plStack_f0,plStack_d8,plStack_e0,plStack_e8,0);
  if (_DAT_23ed90a70 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23ed90a70 = (longlong *)0x0;
  }
  lVar16 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar10 = *(longlong **)(lVar16 + 0x28);
  plVar3 = (longlong *)plVar10[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar16 + 0x30);
  *(undefined4 *)(plVar10 + 8) = 0xffffffff;
  if (plVar3 != (longlong *)0x0) {
    plVar10[2] = 0;
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))();
    }
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  plVar10[0xf] = 0;
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((plVar22 != (longlong *)0x0) && (*plVar22 = *plVar22 + -1, *plVar22 == 0)) {
    (**(code **)(plVar22[1] + 0x30))(plVar22);
  }
  if ((plStack_100 != (longlong *)0x0) &&
     (lVar16 = *plStack_100, *plStack_100 = lVar16 + -1, lVar16 + -1 == 0)) {
    (**(code **)(plStack_100[1] + 0x30))(plStack_100);
  }
  if ((plStack_f8 != (longlong *)0x0) &&
     (lVar16 = *plStack_f8, *plStack_f8 = lVar16 + -1, lVar16 + -1 == 0)) {
    (**(code **)(plStack_f8[1] + 0x30))(plStack_f8);
  }
  if ((plStack_f0 != (longlong *)0x0) &&
     (lVar16 = *plStack_f0, *plStack_f0 = lVar16 + -1, lVar16 + -1 == 0)) {
    (**(code **)(plStack_f0[1] + 0x30))(plStack_f0);
  }
  if ((plStack_d8 != (longlong *)0x0) &&
     (lVar16 = *plStack_d8, *plStack_d8 = lVar16 + -1, lVar16 + -1 == 0)) {
    (**(code **)(plStack_d8[1] + 0x30))(plStack_d8);
  }
  if ((plStack_e0 != (longlong *)0x0) &&
     (lVar16 = *plStack_e0, *plStack_e0 = lVar16 + -1, lVar16 + -1 == 0)) {
    (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
  }
  if ((plStack_e8 != (longlong *)0x0) &&
     (lVar16 = *plStack_e8, *plStack_e8 = lVar16 + -1, lVar16 + -1 == 0)) {
    (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
  }
  lVar16 = *plVar1;
  *plVar1 = lVar16 + -1;
  if (lVar16 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  lVar16 = *plVar2;
  *plVar2 = lVar16 + -1;
  if (lVar16 + -1 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,pcStack_108,pcStack_b8,pcVar20);
  return (code *)0x0;
}
