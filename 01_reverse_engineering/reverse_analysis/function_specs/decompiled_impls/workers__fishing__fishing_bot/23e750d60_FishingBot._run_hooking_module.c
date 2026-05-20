/* ===== 23e750d60 workers.fishing.fishing_bot:FishingBot._run_hooking_module ===== */
/* ghidra_name=FUN_23e750d60 entry=23e750d60 size=6765 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e750d60(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined1 auVar6 [8];
  char cVar7;
  int iVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong lVar13;
  longlong *plVar14;
  code *pcVar15;
  code *pcVar16;
  code *pcVar17;
  longlong *plVar18;
  longlong lVar19;
  code *pcVar20;
  undefined4 uVar21;
  longlong lVar22;
  code *local_b0;
  undefined1 local_98 [16];
  code *local_88 [2];
  undefined1 local_78 [8];
  code *pcStack_70;
  code *local_68 [5];
  
  plVar9 = _DAT_23eedae28;
  plVar1 = (longlong *)*param_3;
  local_68[0] = (code *)0x0;
  local_78 = (undefined1  [8])0x0;
  pcStack_70 = (code *)0x0;
  if (_DAT_23eedae28 == (longlong *)0x0) {
LAB_23e750dba:
    _DAT_23eedae28 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedaef8,DAT_23eedaeb8,0x20);
  }
  else {
    lVar19 = *_DAT_23eedae28;
    if (1 < lVar19) {
      *_DAT_23eedae28 = lVar19 + -1;
      goto LAB_23e750dba;
    }
    if (_DAT_23eedae28[2] != 0) {
      *_DAT_23eedae28 = lVar19 + -1;
      if (lVar19 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e750dba;
    }
  }
  plVar2 = _DAT_23eedae28;
  lVar19 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eedae28 + 9;
  lVar13 = *(longlong *)(lVar19 + 8);
  _DAT_23eedae28[0xf] = lVar13;
  *(longlong **)(lVar19 + 8) = plVar9;
  if ((lVar13 != 0) &&
     (((*(char *)(lVar13 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar13 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar13 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar13 + 0x38))) && (plVar2[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar13 + 0x28);
    *(longlong **)(plVar2[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  lVar19 = _DAT_23eed9198;
  *plVar2 = *plVar2 + 1;
  *(undefined4 *)(plVar2 + 8) = 0;
  uVar5 = DAT_23eed8b40;
  *(undefined4 *)(plVar2 + 5) = 0x314;
  plVar9 = (longlong *)FUN_23e915840(param_1,plVar1,uVar5,*(undefined8 *)(lVar19 + 0x18));
  if (plVar9 == (longlong *)0x0) {
    local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcStack_70 = *(code **)(param_1 + 0x68);
    local_68[0] = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (local_68[0] != (code *)0x0) {
      if (*(longlong **)(local_68[0] + 0x18) != plVar2) {
        plVar11 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        iVar8 = 0x314;
        local_b0 = _PyRuntime_exref;
        plVar9 = (longlong *)0x0;
        goto LAB_23e75126f;
      }
LAB_23e751853:
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      pcVar15 = local_68[0];
      goto LAB_23e75131b;
    }
    plVar11 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    iVar8 = 0x314;
    local_b0 = _PyRuntime_exref;
    plVar9 = (longlong *)0x0;
    local_68[0] = (code *)0x0;
  }
  else {
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    lVar19 = *(longlong *)(DAT_23eed8950 + 0x20);
    if (*(char *)(lVar19 + 10) == '\0') {
      plVar9 = (longlong *)FUN_23a37a020(DAT_23eed8950,_DAT_23eed91a0);
      if (plVar9 == (longlong *)0x0) goto LAB_23e7511f9;
      lVar22 = *plVar9;
LAB_23e751b28:
      if (lVar22 == 0) goto LAB_23e7511f9;
LAB_23e750ee4:
      plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a98);
      if (plVar10 == (longlong *)0x0) {
        local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_70 = *(code **)(param_1 + 0x68);
        local_68[0] = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (local_68[0] != (code *)0x0) {
          plVar9 = *(longlong **)(local_68[0] + 0x18);
          goto joined_r0x00023e75124b;
        }
      }
      else {
        plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8b40);
        if (plVar11 != (longlong *)0x0) {
          *(undefined4 *)(plVar2 + 5) = 0x316;
          local_98._8_8_ = plVar11;
          local_98._0_8_ = plVar10;
          plVar9 = (longlong *)FUN_23e94ed00(param_1,lVar22,local_98);
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))();
          }
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))();
          }
          if (plVar9 == (longlong *)0x0) {
            local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_70 = *(code **)(param_1 + 0x68);
            local_68[0] = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (local_68[0] == (code *)0x0) goto LAB_23e751a40;
            if (plVar2 == *(longlong **)(local_68[0] + 0x18)) goto LAB_23e751853;
            plVar11 = (longlong *)0x0;
            plVar10 = (longlong *)0x0;
            iVar8 = 0x316;
            local_b0 = _PyRuntime_exref;
          }
          else {
            *(undefined4 *)(plVar2 + 5) = 0x317;
            plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar9,DAT_23eed8ca8);
            if (plVar10 != (longlong *)0x0) {
              iVar8 = FUN_23a35f020();
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))();
              }
              lVar19 = _DAT_23eed91a8;
              plVar10 = DAT_23ed6ccf0;
              if (iVar8 == -1) {
                local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                pcStack_70 = *(code **)(param_1 + 0x68);
                local_68[0] = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (local_68[0] == (code *)0x0) goto LAB_23e752510;
                if (*(longlong **)(local_68[0] + 0x18) != plVar2) goto LAB_23e751c3b;
              }
              else {
                if (iVar8 != 0) {
                  *DAT_23ed6ccf0 = *DAT_23ed6ccf0 + 1;
                  if (plVar1 == (longlong *)0x0) {
                    pcStack_70 = (code *)PyUnicode_FromFormat
                                                   (
                                                  "cannot access local variable \'%U\' where it is not associated with a value"
                                                  ,DAT_23eed8d30);
                    pcVar15 = _Py_NoneStruct_exref;
                    local_78 = *(undefined1 (*) [8])PyExc_UnboundLocalError_exref;
                    *(longlong *)local_78 = *(longlong *)local_78 + 1;
                    local_68[0] = (code *)0x0;
                    if (local_78 != (undefined1  [8])pcVar15) {
                      FUN_23e91b1b0(param_1,local_78,local_78 + 8,local_68);
                    }
                    plVar18 = (longlong *)0x0;
                    FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_70);
                    uVar21 = 0x31d;
                  }
                  else {
                    plVar18 = (longlong *)0x0;
                    do {
                      plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a08);
                      if (plVar11 == (longlong *)0x0) {
LAB_23e7518e0:
                        local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pcStack_70 = *(code **)(param_1 + 0x68);
                        local_68[0] = *(code **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        goto LAB_23e751540;
                      }
                      *(undefined4 *)(plVar2 + 5) = 0x31d;
                      plVar12 = (longlong *)FUN_23e91bfe0(param_1,plVar11,DAT_23eed8d38);
                      *plVar11 = *plVar11 + -1;
                      if (*plVar11 == 0) {
                        (**(code **)(plVar11[1] + 0x30))(plVar11);
                      }
                      if (plVar12 == (longlong *)0x0) goto LAB_23e7518e0;
                      iVar8 = FUN_23a35f020(plVar12);
                      *plVar12 = *plVar12 + -1;
                      if (*plVar12 == 0) {
                        (**(code **)(plVar12[1] + 0x30))(plVar12);
                      }
                      if (iVar8 == -1) goto LAB_23e7518e0;
                      pcVar15 = _Py_FalseStruct_exref;
                      if (iVar8 == 0) {
                        pcVar15 = _Py_TrueStruct_exref;
                      }
                      iVar8 = FUN_23a35f020(pcVar15);
                      lVar19 = DAT_23eed8ff8;
                      if (iVar8 == 1) {
                        *(undefined4 *)(plVar2 + 5) = 0x31d;
                        pcVar15 = (code *)FUN_23e915840(param_1,plVar1,DAT_23eed9100,
                                                        *(undefined8 *)(lVar19 + 0x18));
                        if (pcVar15 == (code *)0x0) goto LAB_23e7518e0;
                      }
                      else {
                        *(longlong *)pcVar15 = *(longlong *)pcVar15 + 1;
                      }
                      iVar8 = FUN_23a35f020(pcVar15);
                      *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
                      if (*(longlong *)pcVar15 == 0) {
                        (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
                      }
                      if (iVar8 == -1) goto LAB_23e7518e0;
                      plVar11 = plVar18;
                      if (iVar8 == 0) {
LAB_23e752020:
                        *(undefined4 *)(plVar2 + 5) = 0x326;
                        plVar18 = (longlong *)FUN_23e91bfe0(param_1,plVar9,DAT_23eed8cf0);
                        if (plVar18 == (longlong *)0x0) {
                          local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                          pcStack_70 = *(code **)(param_1 + 0x68);
                          local_68[0] = *(code **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          if (local_68[0] != (code *)0x0) {
                            pcVar15 = local_68[0];
                            if (plVar2 == *(longlong **)(local_68[0] + 0x18)) goto LAB_23e75131b;
                            iVar8 = 0x326;
                            local_b0 = _PyRuntime_exref;
                            goto LAB_23e75126f;
                          }
LAB_23e7528b0:
                          local_b0 = _PyRuntime_exref;
                          iVar8 = 0x326;
                          goto LAB_23e751a60;
                        }
                        *plVar18 = *plVar18 + -1;
                        if (*plVar18 == 0) {
                          (**(code **)(plVar18[1] + 0x30))();
                        }
                        plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8b40);
                        plVar18 = _DAT_23eed91d0;
                        if (plVar12 == (longlong *)0x0) {
                          local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                          pcStack_70 = *(code **)(param_1 + 0x68);
                          local_68[0] = *(code **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          if (local_68[0] == (code *)0x0) {
                            local_b0 = _PyRuntime_exref;
                            local_68[0] = (code *)0x0;
                            goto LAB_23e7527bf;
                          }
                          pcVar15 = local_68[0];
                          if (plVar2 == *(longlong **)(local_68[0] + 0x18)) goto LAB_23e75131b;
                          local_b0 = _PyRuntime_exref;
                          iVar8 = 0x328;
                          goto LAB_23e75126f;
                        }
                        lVar19 = *(longlong *)(param_1 + 0x10);
                        plVar14 = *(longlong **)(lVar19 + 0xe28);
                        if (plVar14 == (longlong *)0x0) {
                          plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
                        }
                        else {
                          lVar13 = plVar14[3];
                          *(int *)(lVar19 + 0xec0) = *(int *)(lVar19 + 0xec0) + -1;
                          *(longlong *)(lVar19 + 0xe28) = lVar13;
                          *plVar14 = 1;
                        }
                        local_b0 = _PyRuntime_exref;
                        *(undefined1 (*) [16])(plVar14 + 4) = (undefined1  [16])0x0;
                        lVar19 = *(longlong *)
                                  (*(longlong *)(*(longlong *)(local_b0 + 0x1f8) + 0x10) + 0x2e8);
                        lVar13 = plVar14[-1];
                        puVar4 = *(undefined8 **)(lVar19 + 8);
                        *puVar4 = plVar14 + -2;
                        plVar14[-2] = lVar19;
                        plVar14[-1] = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar4;
                        *(longlong **)(lVar19 + 8) = plVar14 + -2;
                        *plVar18 = *plVar18 + 1;
                        plVar14[3] = (longlong)plVar18;
                        uVar5 = DAT_23ed6cd28;
                        if (plVar10 == (longlong *)0x0) {
                          pcStack_70 = (code *)PyUnicode_FromFormat
                                                         (
                                                  "cannot access local variable \'%U\' where it is not associated with a value"
                                                  ,DAT_23eed9110);
                          local_78 = *(undefined1 (*) [8])PyExc_UnboundLocalError_exref;
                          *(longlong *)local_78 = *(longlong *)local_78 + 1;
                          local_68[0] = (code *)0x0;
                          if (local_78 != (undefined1  [8])_Py_NoneStruct_exref) {
                            FUN_23e91b1b0(param_1,local_78,local_78 + 8,local_68);
                          }
                          FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_70);
LAB_23e7525c6:
                          *plVar12 = *plVar12 + -1;
                          if (*plVar12 == 0) {
                            (**(code **)(plVar12[1] + 0x30))();
                          }
                          *plVar14 = *plVar14 + -1;
                          if (*plVar14 == 0) {
                            (**(code **)(plVar14[1] + 0x30))();
joined_r0x00023e7525f8:
                            if (local_68[0] != (code *)0x0) goto LAB_23e7525fe;
LAB_23e7527bf:
                            iVar8 = 0x328;
                            goto LAB_23e751a60;
                          }
                          if (local_68[0] == (code *)0x0) goto LAB_23e7527bf;
                          plVar18 = *(longlong **)(local_68[0] + 0x18);
                        }
                        else {
                          if (DAT_23ed6a4c0 == (longlong *)0x0) {
                            plVar18 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                            if (plVar18 == (longlong *)0x0) {
                              PyErr_PrintEx(0);
                              Py_Exit();
                              goto LAB_23e7528b0;
                            }
                            *plVar18 = *plVar18 + 1;
                            DAT_23ed6a4c0 = plVar18;
                          }
                          local_98._8_8_ = uVar5;
                          local_98._0_8_ = plVar10;
                          lVar19 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,local_98);
                          if (lVar19 == 0) {
                            local_68[0] = *(code **)(param_1 + 0x70);
                            local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                            pcStack_70 = *(code **)(param_1 + 0x68);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            goto LAB_23e7525c6;
                          }
                          plVar14[4] = lVar19;
                          plVar18 = DAT_23eed9128;
                          *DAT_23eed9128 = *DAT_23eed9128 + 1;
                          plVar14[5] = (longlong)plVar18;
                          plVar18 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar14);
                          *plVar14 = *plVar14 + -1;
                          if (*plVar14 == 0) {
                            (**(code **)(plVar14[1] + 0x30))();
                          }
                          if (plVar18 != (longlong *)0x0) {
                            *(undefined4 *)(plVar2 + 5) = 0x328;
                            plVar14 = (longlong *)FUN_23e914090(param_1,plVar12);
                            *plVar12 = *plVar12 + -1;
                            if (*plVar12 == 0) {
                              (**(code **)(plVar12[1] + 0x30))();
                            }
                            *plVar18 = *plVar18 + -1;
                            if (*plVar18 == 0) {
                              (**(code **)(plVar18[1] + 0x30))();
                            }
                            if (plVar14 == (longlong *)0x0) {
                              local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                              pcStack_70 = *(code **)(param_1 + 0x68);
                              local_68[0] = *(code **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              if (local_68[0] != (code *)0x0) goto LAB_23e7525fe;
                              local_68[0] = (code *)0x0;
                              goto LAB_23e7527bf;
                            }
                            *plVar14 = *plVar14 + -1;
                            if (*plVar14 == 0) {
                              (**(code **)(plVar14[1] + 0x30))(plVar14);
                            }
                            lVar19 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                            plVar2 = *(longlong **)(lVar19 + 0x28);
                            plVar18 = (longlong *)plVar2[2];
                            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                                 *(undefined8 *)(lVar19 + 0x30);
                            *(undefined4 *)(plVar2 + 8) = 0xffffffff;
                            if (plVar18 != (longlong *)0x0) {
                              plVar2[2] = 0;
                              *plVar18 = *plVar18 + -1;
                              if (*plVar18 == 0) {
                                (**(code **)(plVar18[1] + 0x30))();
                              }
                            }
                            *plVar2 = *plVar2 + -1;
                            if (*plVar2 == 0) {
                              (**(code **)(plVar2[1] + 0x30))(plVar2);
                            }
                            pcVar15 = _Py_NoneStruct_exref;
                            plVar2[0xf] = 0;
                            *(longlong *)pcVar15 = *(longlong *)pcVar15 + 1;
                            *plVar9 = *plVar9 + -1;
                            if (*plVar9 == 0) {
                              (**(code **)(plVar9[1] + 0x30))(plVar9);
                            }
                            *plVar10 = *plVar10 + -1;
                            if (*plVar10 == 0) {
                              (**(code **)(plVar10[1] + 0x30))(plVar10);
                            }
                            if ((plVar11 != (longlong *)0x0) &&
                               (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
                              (**(code **)(plVar11[1] + 0x30))(plVar11);
                            }
                            goto LAB_23e7519ba;
                          }
                          local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                          pcStack_70 = *(code **)(param_1 + 0x68);
                          local_68[0] = *(code **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          *plVar12 = *plVar12 + -1;
                          if (*plVar12 != 0) goto joined_r0x00023e7525f8;
                          FUN_23a334bc0();
                          if (local_68[0] == (code *)0x0) goto LAB_23e7527bf;
LAB_23e7525fe:
                          plVar18 = *(longlong **)(local_68[0] + 0x18);
                        }
                        pcVar15 = local_68[0];
                        if (plVar18 == plVar2) goto LAB_23e75131b;
                        iVar8 = 0x328;
                        goto LAB_23e75126f;
                      }
                      *(undefined4 *)(plVar2 + 5) = 0x31e;
                      plVar11 = (longlong *)FUN_23e91bfe0(param_1,plVar9,_DAT_23eed91b8);
                      if (plVar11 == (longlong *)0x0) {
                        local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pcStack_70 = *(code **)(param_1 + 0x68);
                        local_68[0] = *(code **)(param_1 + 0x70);
                        uVar21 = 0x31e;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        pcVar15 = _Py_NoneStruct_exref;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        goto LAB_23e75154d;
                      }
                      if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0))
                      {
                        (**(code **)(plVar18[1] + 0x30))(plVar18);
                      }
                      iVar8 = FUN_23e913250(plVar11,_DAT_23eed91c0);
                      plVar18 = plVar11;
                      if (iVar8 == -1) {
                        local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pcStack_70 = *(code **)(param_1 + 0x68);
                        local_68[0] = *(code **)(param_1 + 0x70);
                        uVar21 = 799;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        pcVar15 = _Py_NoneStruct_exref;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        goto LAB_23e75154d;
                      }
                      if (iVar8 == 1) {
                        cVar7 = FUN_23e8d9ac0(plVar1,DAT_23eed8b00,_Py_TrueStruct_exref);
                        if (cVar7 == '\0') {
                          local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                          pcStack_70 = *(code **)(param_1 + 0x68);
                          local_68[0] = *(code **)(param_1 + 0x70);
                          uVar21 = 800;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          pcVar15 = _Py_NoneStruct_exref;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        }
                        else {
                          plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a08);
                          if (plVar12 != (longlong *)0x0) {
                            *(undefined4 *)(plVar2 + 5) = 0x321;
                            plVar14 = (longlong *)FUN_23e91bfe0(param_1,plVar12,DAT_23eed8cc8);
                            *plVar12 = *plVar12 + -1;
                            if (*plVar12 == 0) {
                              (**(code **)(plVar12[1] + 0x30))(plVar12);
                            }
                            if (plVar14 != (longlong *)0x0) {
                              *plVar14 = *plVar14 + -1;
                              if (*plVar14 == 0) {
                                (**(code **)(plVar14[1] + 0x30))(plVar14);
                              }
                              goto LAB_23e752020;
                            }
                          }
                          local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                          pcStack_70 = *(code **)(param_1 + 0x68);
                          local_68[0] = *(code **)(param_1 + 0x70);
                          uVar21 = 0x321;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          pcVar15 = _Py_NoneStruct_exref;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        }
                        goto LAB_23e75154d;
                      }
                      if (plVar10 == (longlong *)0x0) {
                        pcStack_70 = (code *)PyUnicode_FromFormat
                                                       (
                                                  "cannot access local variable \'%U\' where it is not associated with a value"
                                                  ,DAT_23eed9110);
                        pcVar15 = _Py_NoneStruct_exref;
                        local_78 = *(undefined1 (*) [8])PyExc_UnboundLocalError_exref;
                        *(longlong *)local_78 = *(longlong *)local_78 + 1;
                        local_68[0] = (code *)0x0;
                        if (local_78 != (undefined1  [8])pcVar15) {
                          FUN_23e91b1b0(param_1,local_78,local_78 + 8,local_68);
                        }
                        FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_70);
                        uVar21 = 0x323;
                        goto LAB_23e75154d;
                      }
                      local_98._0_8_ = plVar10;
                      FUN_23e8d34a0(local_98);
                      plVar10 = (longlong *)local_98._0_8_;
                      lVar13 = FUN_23e8e0ba0();
                      lVar19 = _DAT_23eed91c8;
                      if (lVar13 == 0) {
                        FUN_23e915740(param_1,local_78,DAT_23eed8c70);
LAB_23e751c74:
                        uVar21 = 0x324;
                        pcVar15 = _Py_NoneStruct_exref;
                        goto LAB_23e75154d;
                      }
                      *(undefined4 *)(plVar2 + 5) = 0x324;
                      plVar11 = (longlong *)
                                FUN_23e915840(param_1,lVar13,DAT_23eed8d40,
                                              *(undefined8 *)(lVar19 + 0x18));
                      if (plVar11 == (longlong *)0x0) {
                        local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pcStack_70 = *(code **)(param_1 + 0x68);
                        local_68[0] = *(code **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        goto LAB_23e751c74;
                      }
                      *plVar11 = *plVar11 + -1;
                      if (*plVar11 == 0) {
                        (**(code **)(plVar11[1] + 0x30))(plVar11);
                      }
                      lVar19 = *(longlong *)(param_1 + 0x10);
                      if ((((*(int *)(*(longlong *)(lVar19 + 0x28) + 0x160) != 0) ||
                           (*(int *)(lVar19 + 0x78) != 0)) &&
                          (iVar8 = Py_MakePendingCalls(), iVar8 < 0)) &&
                         (pcVar15 = *(code **)(param_1 + 0x60), pcVar15 != (code *)0x0))
                      goto LAB_23e75150f;
                      if (*(int *)(lVar19 + 0x68) == 0) {
                        plVar11 = *(longlong **)(param_1 + 0x90);
                      }
                      else {
                        PyEval_SaveThread();
                        PyEval_AcquireThread(param_1);
                        plVar11 = *(longlong **)(param_1 + 0x90);
                      }
                    } while (plVar11 == (longlong *)0x0);
                    plVar12 = *(longlong **)(param_1 + 0x60);
                    plVar14 = *(longlong **)(param_1 + 0x68);
                    *(undefined8 *)(param_1 + 0x90) = 0;
                    plVar3 = *(longlong **)(param_1 + 0x70);
                    *(longlong **)(param_1 + 0x60) = plVar11;
                    *plVar11 = *plVar11 + 1;
                    *(undefined8 *)(param_1 + 0x68) = 0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
                      (**(code **)(plVar12[1] + 0x30))();
                    }
                    if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                      (**(code **)(plVar14[1] + 0x30))(plVar14);
                    }
                    if ((plVar3 != (longlong *)0x0) && (*plVar3 = *plVar3 + -1, *plVar3 == 0)) {
                      (**(code **)(plVar3[1] + 0x30))(plVar3);
                    }
                    pcVar15 = *(code **)(param_1 + 0x60);
LAB_23e75150f:
                    local_68[0] = *(code **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    pcStack_70 = *(code **)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    local_78 = (undefined1  [8])pcVar15;
LAB_23e751540:
                    uVar21 = 0x31d;
                    pcVar15 = _Py_NoneStruct_exref;
                  }
LAB_23e75154d:
                  pcVar16 = local_68[0];
                  local_98._8_8_ = pcStack_70;
                  local_98._0_8_ = local_78;
                  local_68[0] = (code *)0x0;
                  _local_78 = (undefined1  [16])0x0;
                  local_88[0] = pcVar16;
                  plVar12 = *(longlong **)(param_1 + 0x138);
                  if (plVar12 != (longlong *)0x0) {
                    *plVar12 = *plVar12 + 1;
                  }
                  pcVar17 = DAT_23ed6a4f8;
                  if (pcVar16 == (code *)0x0) {
                    if (DAT_23ed6a4f8 == (code *)0x0) {
                      pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                    }
                    else {
                      pcVar16 = *(code **)DAT_23ed6a4f8;
                      *(longlong *)DAT_23ed6a4f8 = 1;
                      DAT_23ed6a4f8 = pcVar16;
                      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                    }
                    local_b0 = _PyRuntime_exref;
                    *(longlong *)(pcVar17 + 0x10) = 0;
                    *(longlong **)(pcVar17 + 0x18) = plVar2;
                    *plVar2 = *plVar2 + 1;
                    lVar19 = *(longlong *)(local_b0 + 0x1f8);
                    *(undefined4 *)(pcVar17 + 0x24) = uVar21;
                    lVar19 = *(longlong *)(lVar19 + 0x10);
                    *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
                    lVar19 = *(longlong *)(lVar19 + 0x2e8);
                    lVar13 = *(longlong *)(pcVar17 + -8);
                    puVar4 = *(undefined8 **)(lVar19 + 8);
                    *puVar4 = pcVar17 + -0x10;
                    *(longlong *)(pcVar17 + -0x10) = lVar19;
                    *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar4
                    ;
                    *(code **)(lVar19 + 8) = pcVar17 + -0x10;
                    if ((local_88[0] != (code *)0x0) &&
                       (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1,
                       *(longlong *)local_88[0] == 0)) {
                      (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))(local_88[0]);
                    }
                  }
                  else {
                    if (DAT_23ed6a4f8 == (code *)0x0) {
                      pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                    }
                    else {
                      pcVar20 = *(code **)DAT_23ed6a4f8;
                      *(longlong *)DAT_23ed6a4f8 = 1;
                      DAT_23ed6a4f8 = pcVar20;
                      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                    }
                    local_b0 = _PyRuntime_exref;
                    *(longlong **)(pcVar17 + 0x18) = plVar2;
                    *plVar2 = *plVar2 + 1;
                    lVar19 = *(longlong *)(local_b0 + 0x1f8);
                    *(undefined4 *)(pcVar17 + 0x24) = uVar21;
                    lVar19 = *(longlong *)(lVar19 + 0x10);
                    *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
                    lVar19 = *(longlong *)(lVar19 + 0x2e8);
                    lVar13 = *(longlong *)(pcVar17 + -8);
                    puVar4 = *(undefined8 **)(lVar19 + 8);
                    *puVar4 = pcVar17 + -0x10;
                    *(longlong *)(pcVar17 + -0x10) = lVar19;
                    *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar4
                    ;
                    *(code **)(lVar19 + 8) = pcVar17 + -0x10;
                    *(code **)(pcVar17 + 0x10) = pcVar16;
                    *(longlong *)pcVar16 = *(longlong *)pcVar16 + 1;
                    if ((local_88[0] != (code *)0x0) &&
                       (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1,
                       *(longlong *)local_88[0] == 0)) {
                      (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))(local_88[0]);
                    }
                  }
                  local_88[0] = pcVar17;
                  if (((code *)local_98._0_8_ != pcVar15) && ((code *)local_98._0_8_ != (code *)0x0)
                     ) {
                    FUN_23e91b1b0(param_1,local_98,local_98 + 8,local_88);
                  }
                  plVar11 = *(longlong **)(local_98._8_8_ + 0x28);
                  if (local_88[0] == pcVar15) {
                    pcVar16 = (code *)0x0;
                  }
                  else {
                    pcVar16 = local_88[0];
                    if (local_88[0] != (code *)0x0) {
                      *(longlong *)local_88[0] = *(longlong *)local_88[0] + 1;
                    }
                  }
                  *(code **)(local_98._8_8_ + 0x28) = pcVar16;
                  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
                    (**(code **)(plVar11[1] + 0x30))();
                  }
                  plVar11 = *(longlong **)(param_1 + 0x138);
                  *(undefined8 *)(param_1 + 0x138) = local_98._8_8_;
                  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
                    (**(code **)(plVar11[1] + 0x30))();
                  }
                  *(longlong *)local_98._0_8_ = *(longlong *)local_98._0_8_ + -1;
                  if (*(longlong *)local_98._0_8_ == 0) {
                    (**(code **)(*(longlong *)(local_98._0_8_ + 8) + 0x30))();
                  }
                  if ((local_88[0] != (code *)0x0) &&
                     (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1,
                     *(longlong *)local_88[0] == 0)) {
                    (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))();
                  }
                  uVar5 = DAT_23eed8cf0;
                  local_88[0] = (code *)0x0;
                  local_98 = (undefined1  [16])0x0;
                  *(undefined4 *)(plVar2 + 5) = 0x326;
                  plVar14 = (longlong *)FUN_23e91bfe0(param_1,plVar9,uVar5);
                  plVar11 = plVar18;
                  if (plVar14 == (longlong *)0x0) {
                    pcVar15 = *(code **)(param_1 + 0x70);
                    pcVar20 = *(code **)(param_1 + 0x138);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    iVar8 = 0x326;
                    pcVar17 = *(code **)(param_1 + 0x60);
                    pcVar16 = *(code **)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e751d7c:
                    *(longlong **)(param_1 + 0x138) = plVar12;
                    if (pcVar20 != (code *)0x0) goto LAB_23e7517b6;
                    local_78 = (undefined1  [8])pcVar17;
                    pcStack_70 = pcVar16;
                    if (pcVar15 == (code *)0x0) {
                      local_68[0] = (code *)0x0;
                      goto LAB_23e751a60;
                    }
                  }
                  else {
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      (**(code **)(plVar14[1] + 0x30))(plVar14);
                    }
                    pcVar16 = *(code **)(param_1 + 0x138);
                    pcStack_70 = pcVar16;
                    if ((pcVar16 == (code *)0x0) || (pcVar16 == pcVar15)) {
                      pcVar15 = (code *)0x0;
                      pcVar17 = *(code **)PyExc_RuntimeError_exref;
                      pcVar16 = (code *)PyUnicode_FromString("No active exception to reraise");
                      iVar8 = 0x31c;
                      pcVar20 = *(code **)(param_1 + 0x138);
                      *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
                      goto LAB_23e751d7c;
                    }
                    pcVar17 = *(code **)(pcVar16 + 8);
                    pcVar15 = *(code **)(pcVar16 + 0x28);
                    *(longlong *)pcVar16 = *(longlong *)pcVar16 + 1;
                    *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
                    pcVar20 = pcVar16;
                    if (pcVar15 == (code *)0x0) {
                      *(longlong **)(param_1 + 0x138) = plVar12;
                      iVar8 = 0;
                    }
                    else {
                      *(longlong *)pcVar15 = *(longlong *)pcVar15 + 1;
                      if (*(longlong **)(pcVar15 + 0x18) == plVar2) {
                        *(undefined4 *)(plVar2 + 5) = *(undefined4 *)(pcVar15 + 0x24);
                      }
                      *(longlong **)(param_1 + 0x138) = plVar12;
                      iVar8 = 0;
                    }
LAB_23e7517b6:
                    local_68[0] = (code *)0x0;
                    _local_78 = (undefined1  [16])0x0;
                    *(longlong *)pcVar20 = *(longlong *)pcVar20 + -1;
                    if (*(longlong *)pcVar20 == 0) {
                      (**(code **)(*(longlong *)(pcVar20 + 8) + 0x30))();
                    }
                    local_78 = (undefined1  [8])pcVar17;
                    pcStack_70 = pcVar16;
                    if (pcVar15 == (code *)0x0) {
                      local_68[0] = (code *)0x0;
                      if (iVar8 == 0) {
                        iVar8 = (int)plVar2[5];
                      }
                      goto LAB_23e751a60;
                    }
                  }
                  if (*(longlong **)(pcVar15 + 0x18) == plVar2) goto LAB_23e75131b;
                  local_68[0] = pcVar15;
                  if (iVar8 == 0) {
                    iVar8 = (int)plVar2[5];
                  }
                  goto LAB_23e75126f;
                }
                *(undefined4 *)(plVar2 + 5) = 0x318;
                plVar10 = (longlong *)
                          FUN_23e915840(param_1,plVar1,DAT_23eed8b40,*(undefined8 *)(lVar19 + 0x18))
                ;
                if (plVar10 != (longlong *)0x0) {
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                  }
                  pcVar15 = _Py_NoneStruct_exref;
                  lVar19 = *(longlong *)(param_1 + 0x38);
                  lVar13 = *(longlong *)(lVar19 + 8);
                  *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
                  plVar2 = *(longlong **)(lVar13 + 0x28);
                  plVar10 = (longlong *)plVar2[2];
                  *(undefined8 *)(lVar19 + 8) = *(undefined8 *)(lVar13 + 0x30);
                  *(undefined4 *)(plVar2 + 8) = 0xffffffff;
                  if (plVar10 != (longlong *)0x0) {
                    plVar2[2] = 0;
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      (**(code **)(plVar10[1] + 0x30))();
                    }
                  }
                  *plVar2 = *plVar2 + -1;
                  if (*plVar2 == 0) {
                    (**(code **)(plVar2[1] + 0x30))(plVar2);
                  }
                  plVar2[0xf] = 0;
                  *plVar9 = *plVar9 + -1;
                  if (*plVar9 == 0) {
                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                  }
LAB_23e7519ba:
                  *plVar1 = *plVar1 + -1;
                  if (*plVar1 != 0) {
                    return pcVar15;
                  }
                  (**(code **)(plVar1[1] + 0x30))(plVar1);
                  return pcVar15;
                }
                local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                pcStack_70 = *(code **)(param_1 + 0x68);
                local_68[0] = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (local_68[0] == (code *)0x0) {
                  plVar11 = (longlong *)0x0;
                  iVar8 = 0x318;
                  local_b0 = _PyRuntime_exref;
                  plVar10 = (longlong *)0x0;
                  local_68[0] = (code *)0x0;
                  goto LAB_23e751a60;
                }
                if (plVar2 != *(longlong **)(local_68[0] + 0x18)) {
                  plVar11 = (longlong *)0x0;
                  iVar8 = 0x318;
                  local_b0 = _PyRuntime_exref;
                  plVar10 = (longlong *)0x0;
                  goto LAB_23e75126f;
                }
              }
              plVar11 = (longlong *)0x0;
              plVar10 = (longlong *)0x0;
              pcVar15 = local_68[0];
              goto LAB_23e75131b;
            }
            local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_70 = *(code **)(param_1 + 0x68);
            local_68[0] = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (local_68[0] == (code *)0x0) {
LAB_23e752510:
              plVar11 = (longlong *)0x0;
              plVar10 = (longlong *)0x0;
              iVar8 = 0x317;
              local_b0 = _PyRuntime_exref;
              goto LAB_23e751a60;
            }
            plVar11 = (longlong *)0x0;
            plVar10 = (longlong *)0x0;
            pcVar15 = local_68[0];
            if (plVar2 == *(longlong **)(local_68[0] + 0x18)) goto LAB_23e75131b;
LAB_23e751c3b:
            plVar10 = (longlong *)0x0;
            plVar11 = (longlong *)0x0;
            iVar8 = 0x317;
            local_b0 = _PyRuntime_exref;
          }
LAB_23e75126f:
          pcVar16 = local_68[0];
          pcVar15 = DAT_23ed6a4f8;
          if (DAT_23ed6a4f8 == (code *)0x0) {
            pcVar15 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
          }
          else {
            pcVar17 = *(code **)DAT_23ed6a4f8;
            *(longlong *)DAT_23ed6a4f8 = 1;
            DAT_23ed6a4f8 = pcVar17;
            DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
          }
          *(longlong **)(pcVar15 + 0x18) = plVar2;
          *plVar2 = *plVar2 + 1;
          lVar19 = *(longlong *)(local_b0 + 0x1f8);
          *(int *)(pcVar15 + 0x24) = iVar8;
          *(undefined4 *)(pcVar15 + 0x20) = 0xffffffff;
          lVar19 = *(longlong *)(*(longlong *)(lVar19 + 0x10) + 0x2e8);
          lVar13 = *(longlong *)(pcVar15 + -8);
          puVar4 = *(undefined8 **)(lVar19 + 8);
          *puVar4 = pcVar15 + -0x10;
          *(longlong *)(pcVar15 + -0x10) = lVar19;
          *(ulonglong *)(pcVar15 + -8) = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar4;
          *(code **)(lVar19 + 8) = pcVar15 + -0x10;
          *(code **)(pcVar15 + 0x10) = pcVar16;
          *(longlong *)pcVar16 = *(longlong *)pcVar16 + 1;
          if ((local_68[0] != (code *)0x0) &&
             (*(longlong *)local_68[0] = *(longlong *)local_68[0] + -1,
             *(longlong *)local_68[0] == 0)) {
            (**(code **)(*(longlong *)(local_68[0] + 8) + 0x30))();
          }
          goto LAB_23e75131b;
        }
        local_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_70 = *(code **)(param_1 + 0x68);
        local_68[0] = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))();
          if (local_68[0] != (code *)0x0) {
            plVar9 = *(longlong **)(local_68[0] + 0x18);
joined_r0x00023e75124b:
            if (plVar2 == plVar9) goto LAB_23e751853;
            plVar10 = (longlong *)0x0;
            plVar11 = (longlong *)0x0;
            plVar9 = (longlong *)0x0;
            iVar8 = 0x316;
            local_b0 = _PyRuntime_exref;
            goto LAB_23e75126f;
          }
        }
        else if (local_68[0] != (code *)0x0) {
          plVar9 = *(longlong **)(local_68[0] + 0x18);
          goto joined_r0x00023e75124b;
        }
      }
    }
    else {
      iVar8 = *(int *)(lVar19 + 0xc);
      if (*(int *)(lVar19 + 0xc) == 0) {
        *(int *)(lVar19 + 0xc) = DAT_23ec1545c;
        iVar8 = DAT_23ec1545c;
        DAT_23ec1545c = DAT_23ec1545c + 1;
      }
      if (_DAT_23ec15440 != iVar8) {
        _DAT_23ec15440 = iVar8;
        _DAT_23eedae20 = FUN_23e8cbd60(lVar19,_DAT_23eed91a0,*(undefined8 *)(_DAT_23eed91a0 + 0x18))
        ;
      }
      if (-1 < _DAT_23eedae20) {
        lVar13 = lVar19 + 0x20 + (1L << (*(byte *)(lVar19 + 9) & 0x3f));
        lVar22 = *(longlong *)(lVar13 + 8 + _DAT_23eedae20 * 0x10);
        if (lVar22 != 0) goto LAB_23e750ee4;
        _DAT_23eedae20 = FUN_23e8cbd60(lVar19,_DAT_23eed91a0,*(undefined8 *)(_DAT_23eed91a0 + 0x18))
        ;
        if (-1 < _DAT_23eedae20) {
          lVar22 = *(longlong *)(lVar13 + 8 + _DAT_23eedae20 * 0x10);
          goto LAB_23e751b28;
        }
      }
LAB_23e7511f9:
      plVar9 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eed91a0);
      if ((plVar9 != (longlong *)0x0) && (lVar22 = *plVar9, lVar22 != 0)) goto LAB_23e750ee4;
      FUN_23e915740(param_1,local_78,_DAT_23eed91a0);
      if (local_68[0] != (code *)0x0) {
        plVar9 = *(longlong **)(local_68[0] + 0x18);
        goto joined_r0x00023e75124b;
      }
    }
LAB_23e751a40:
    plVar11 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    iVar8 = 0x316;
    local_b0 = _PyRuntime_exref;
  }
LAB_23e751a60:
  pcVar15 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar15 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    pcVar16 = local_68[0];
  }
  else {
    pcVar16 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar16;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    pcVar16 = (code *)0x0;
  }
  *(longlong *)(pcVar15 + 0x10) = 0;
  *(longlong **)(pcVar15 + 0x18) = plVar2;
  *plVar2 = *plVar2 + 1;
  lVar19 = *(longlong *)(local_b0 + 0x1f8);
  *(int *)(pcVar15 + 0x24) = iVar8;
  lVar19 = *(longlong *)(lVar19 + 0x10);
  *(undefined4 *)(pcVar15 + 0x20) = 0xffffffff;
  lVar19 = *(longlong *)(lVar19 + 0x2e8);
  lVar13 = *(longlong *)(pcVar15 + -8);
  puVar4 = *(undefined8 **)(lVar19 + 8);
  *puVar4 = pcVar15 + -0x10;
  *(longlong *)(pcVar15 + -0x10) = lVar19;
  *(ulonglong *)(pcVar15 + -8) = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar4;
  *(code **)(lVar19 + 8) = pcVar15 + -0x10;
  if ((pcVar16 != (code *)0x0) &&
     (*(longlong *)pcVar16 = *(longlong *)pcVar16 + -1, *(longlong *)pcVar16 == 0)) {
    (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))();
  }
LAB_23e75131b:
  local_68[0] = pcVar15;
  FUN_23e8bba40(plVar2,&DAT_23ec5dee6,plVar1,plVar9,plVar10,plVar11);
  if (_DAT_23eedae28 == plVar2) {
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    _DAT_23eedae28 = (longlong *)0x0;
  }
  lVar19 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar2 = *(longlong **)(lVar19 + 0x28);
  plVar18 = (longlong *)plVar2[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar19 + 0x30);
  *(undefined4 *)(plVar2 + 8) = 0xffffffff;
  if (plVar18 != (longlong *)0x0) {
    plVar2[2] = 0;
    *plVar18 = *plVar18 + -1;
    if (*plVar18 == 0) {
      (**(code **)(plVar18[1] + 0x30))();
    }
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  pcVar16 = local_68[0];
  pcVar15 = pcStack_70;
  auVar6 = local_78;
  plVar2[0xf] = 0;
  _local_78 = (undefined1  [16])0x0;
  local_68[0] = (code *)0x0;
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  *plVar1 = *plVar1 + -1;
  local_68[0] = pcVar16;
  local_78 = auVar6;
  pcStack_70 = pcVar15;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,local_78,pcStack_70,local_68[0]);
  return (code *)0x0;
}
