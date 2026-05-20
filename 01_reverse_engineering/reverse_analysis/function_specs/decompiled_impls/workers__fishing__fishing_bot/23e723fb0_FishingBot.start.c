/* ===== 23e723fb0 workers.fishing.fishing_bot:FishingBot.start ===== */
/* ghidra_name=FUN_23e723fb0 entry=23e723fb0 size=7115 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e723fb0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong *plVar8;
  bool bVar9;
  char cVar10;
  int iVar11;
  longlong lVar12;
  longlong *plVar13;
  code *pcVar14;
  code *pcVar15;
  longlong *plVar16;
  longlong *plVar17;
  longlong *plVar18;
  longlong *plVar19;
  longlong lVar20;
  undefined8 uVar21;
  code *pcVar22;
  code *pcVar23;
  code *pcVar24;
  code *pcVar25;
  code *pcVar26;
  longlong *plVar27;
  undefined1 auVar28 [8];
  undefined4 uVar29;
  longlong *plStack_f8;
  int iStack_f0;
  undefined1 auStack_b8 [16];
  code *pcStack_a8;
  undefined1 auStack_98 [8];
  code *pcStack_90;
  code *apcStack_88 [2];
  code *pcStack_78;
  code *pcStack_70;
  code *pcStack_68;
  
  plVar13 = _DAT_23eedae78;
  plVar2 = (longlong *)*param_3;
  apcStack_88[0] = (code *)0x0;
  auStack_98 = (undefined1  [8])0x0;
  pcStack_90 = (code *)0x0;
  if (_DAT_23eedae78 == (longlong *)0x0) {
LAB_23e72400d:
    _DAT_23eedae78 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedaf20,DAT_23eedaeb8,0x28);
  }
  else {
    lVar12 = *_DAT_23eedae78;
    if (1 < lVar12) {
      *_DAT_23eedae78 = lVar12 + -1;
      goto LAB_23e72400d;
    }
    if (_DAT_23eedae78[2] != 0) {
      *_DAT_23eedae78 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      goto LAB_23e72400d;
    }
  }
  plVar8 = _DAT_23eedae78;
  lVar12 = *(longlong *)(param_1 + 0x38);
  plVar13 = _DAT_23eedae78 + 9;
  lVar20 = *(longlong *)(lVar12 + 8);
  _DAT_23eedae78[0xf] = lVar20;
  *(longlong **)(lVar12 + 8) = plVar13;
  if ((lVar20 != 0) &&
     (((*(char *)(lVar20 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar20 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar20 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar20 + 0x38))) && (plVar8[0xe] != 0)))) {
    plVar13 = *(longlong **)(lVar20 + 0x28);
    *(longlong **)(plVar8[0xe] + 0x10) = plVar13;
    if (plVar13 != (longlong *)0x0) {
      *plVar13 = *plVar13 + 1;
    }
  }
  *plVar8 = *plVar8 + 1;
  *(undefined4 *)(plVar8 + 8) = 0;
  lVar12 = FUN_23e8e0a50();
  if (lVar12 == 0) {
    FUN_23e915740(param_1,auStack_98,_DAT_23eed8d18);
    plVar13 = (longlong *)0x0;
    if (apcStack_88[0] != (code *)0x0) goto LAB_23e724f8a;
LAB_23e725088:
    plStack_f8 = (longlong *)0x0;
    plVar27 = (longlong *)0x0;
    pcVar14 = (code *)0x0;
    plVar13 = (longlong *)0x0;
    uVar29 = 0x10a;
    goto LAB_23e7250a0;
  }
  *(undefined4 *)(plVar8 + 5) = 0x10a;
  plVar13 = (longlong *)FUN_23e94bb80(param_1,lVar12,_DAT_23eed8d20);
  if (plVar13 == (longlong *)0x0) {
    auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcStack_90 = *(code **)(param_1 + 0x68);
    apcStack_88[0] = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (apcStack_88[0] == (code *)0x0) goto LAB_23e725088;
LAB_23e724f8a:
    plVar27 = (longlong *)0x0;
    pcVar14 = (code *)0x0;
    uVar29 = 0x10a;
    plStack_f8 = (longlong *)0x0;
    pcVar15 = pcVar14;
    if (plVar8 == *(longlong **)(apcStack_88[0] + 0x18)) {
      plVar13 = (longlong *)0x0;
      pcVar22 = apcStack_88[0];
      goto LAB_23e724d00;
    }
LAB_23e724fb0:
    pcVar14 = apcStack_88[0];
    pcVar22 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar22 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar23 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar23;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar23 = _PyRuntime_exref;
    *(longlong **)(pcVar22 + 0x18) = plVar8;
    *plVar8 = *plVar8 + 1;
    lVar12 = *(longlong *)(pcVar23 + 0x1f8);
    *(undefined4 *)(pcVar22 + 0x20) = 0xffffffff;
    *(undefined4 *)(pcVar22 + 0x24) = uVar29;
    lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
    lVar20 = *(longlong *)(pcVar22 + -8);
    puVar4 = *(undefined8 **)(lVar12 + 8);
    *puVar4 = pcVar22 + -0x10;
    *(longlong *)(pcVar22 + -0x10) = lVar12;
    *(ulonglong *)(pcVar22 + -8) = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar4;
    *(code **)(lVar12 + 8) = pcVar22 + -0x10;
    *(code **)(pcVar22 + 0x10) = pcVar14;
    *(longlong *)pcVar14 = *(longlong *)pcVar14 + 1;
    pcVar14 = pcVar15;
    pcVar15 = apcStack_88[0];
  }
  else {
    lVar12 = *(longlong *)(DAT_23eed8950 + 0x20);
    if (*(char *)(lVar12 + 10) == '\0') {
      plVar27 = (longlong *)FUN_23a37a020(DAT_23eed8950,_DAT_23eed8d28);
      if (plVar27 == (longlong *)0x0) goto LAB_23e7248a9;
      lVar20 = *plVar27;
LAB_23e725298:
      if (lVar20 == 0) goto LAB_23e7248a9;
LAB_23e724133:
      pcVar14 = (code *)FUN_23e8bc2f0(plVar2,DAT_23eed8aa8);
      if (pcVar14 == (code *)0x0) {
        auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_90 = *(code **)(param_1 + 0x68);
        apcStack_88[0] = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (apcStack_88[0] != (code *)0x0) {
          if (*(longlong **)(apcStack_88[0] + 0x18) != plVar8) {
            plStack_f8 = (longlong *)0x0;
            plVar27 = (longlong *)0x0;
            uVar29 = 0x10c;
            pcVar15 = (code *)0x0;
            goto LAB_23e724fb0;
          }
LAB_23e724cec:
          plStack_f8 = (longlong *)0x0;
          plVar27 = (longlong *)0x0;
          pcVar14 = (code *)0x0;
          pcVar22 = apcStack_88[0];
          goto LAB_23e724d00;
        }
        goto LAB_23e725540;
      }
      pcVar15 = (code *)FUN_23e8bd350();
      if (pcVar15 == (code *)0x0) {
        auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_90 = *(code **)(param_1 + 0x68);
        apcStack_88[0] = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(longlong *)pcVar14 = *(longlong *)pcVar14 + -1;
        if (*(longlong *)pcVar14 == 0) {
          (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))();
        }
        if (apcStack_88[0] != (code *)0x0) {
          if (*(longlong **)(apcStack_88[0] + 0x18) != plVar8) {
            plStack_f8 = (longlong *)0x0;
            uVar29 = 0x10c;
            plVar27 = (longlong *)0x0;
            pcVar15 = (code *)0x0;
            goto LAB_23e724fb0;
          }
          goto LAB_23e724cec;
        }
        goto LAB_23e725540;
      }
      *(undefined4 *)(plVar8 + 5) = 0x10c;
      pcStack_78 = pcVar14;
      pcStack_70 = pcVar15;
      plStack_f8 = (longlong *)FUN_23e94ed00(param_1,lVar20,&pcStack_78);
      *(longlong *)pcVar14 = *(longlong *)pcVar14 + -1;
      if (*(longlong *)pcVar14 == 0) {
        (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))();
      }
      *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
      if (*(longlong *)pcVar15 == 0) {
        (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))();
      }
      if (plStack_f8 == (longlong *)0x0) {
        auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_90 = *(code **)(param_1 + 0x68);
        apcStack_88[0] = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (apcStack_88[0] != (code *)0x0) {
          if (plVar8 != *(longlong **)(apcStack_88[0] + 0x18)) {
            plVar27 = (longlong *)0x0;
            uVar29 = 0x10c;
            pcVar15 = (code *)0x0;
            goto LAB_23e724fb0;
          }
          goto LAB_23e724cec;
        }
        goto LAB_23e725540;
      }
      if (plVar2 == (longlong *)0x0) {
        pcStack_90 = (code *)PyUnicode_FromFormat
                                       ("cannot access local variable \'%U\' where it is not associated with a value"
                                        ,DAT_23eed8d30);
        auStack_98 = *(undefined1 (*) [8])PyExc_UnboundLocalError_exref;
        *(longlong *)auStack_98 = *(longlong *)auStack_98 + 1;
        apcStack_88[0] = (code *)0x0;
        if (auStack_98 != (undefined1  [8])_Py_NoneStruct_exref) {
          FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,apcStack_88);
        }
        FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_90);
        if (apcStack_88[0] != (code *)0x0) {
          pcVar15 = (code *)0x0;
          uVar29 = 0x10e;
          plVar16 = *(longlong **)(apcStack_88[0] + 0x18);
          pcVar14 = pcVar15;
          plVar27 = (longlong *)0x0;
          goto joined_r0x00023e725924;
        }
        plVar27 = (longlong *)0x0;
        pcVar14 = (code *)0x0;
        uVar29 = 0x10e;
      }
      else {
        pcVar14 = (code *)0x0;
        plVar27 = (longlong *)0x0;
LAB_23e7241da:
        do {
          plVar16 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eed89b0);
          if (plVar16 == (longlong *)0x0) {
LAB_23e7252e0:
            auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_90 = *(code **)(param_1 + 0x68);
            apcStack_88[0] = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (apcStack_88[0] == (code *)0x0) {
LAB_23e725a60:
              uVar29 = 0x10e;
              goto LAB_23e7250a0;
            }
            plVar16 = *(longlong **)(apcStack_88[0] + 0x18);
joined_r0x00023e72549b:
            pcVar22 = apcStack_88[0];
            if (plVar16 == plVar8) goto LAB_23e724d00;
            uVar29 = 0x10e;
            pcVar15 = pcVar14;
            goto LAB_23e724fb0;
          }
          *(undefined4 *)(plVar8 + 5) = 0x10e;
          plVar17 = (longlong *)FUN_23e91bfe0(param_1,plVar16,DAT_23eed8d38);
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))();
          }
          if (plVar17 == (longlong *)0x0) {
            auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_90 = *(code **)(param_1 + 0x68);
            apcStack_88[0] = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (apcStack_88[0] == (code *)0x0) goto LAB_23e725a60;
            plVar16 = *(longlong **)(apcStack_88[0] + 0x18);
            goto joined_r0x00023e72549b;
          }
          iVar11 = FUN_23a35f020();
          *plVar17 = *plVar17 + -1;
          if (*plVar17 == 0) {
            (**(code **)(plVar17[1] + 0x30))();
          }
          if (iVar11 == -1) goto LAB_23e7252e0;
          pcVar15 = _Py_FalseStruct_exref;
          if (iVar11 == 0) {
            pcVar15 = _Py_TrueStruct_exref;
          }
          iVar11 = FUN_23a35f020(pcVar15);
          if (iVar11 == 0) {
            lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
            plVar8 = *(longlong **)(lVar12 + 0x28);
            plVar16 = (longlong *)plVar8[2];
            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
            *(undefined4 *)(plVar8 + 8) = 0xffffffff;
            if (plVar16 != (longlong *)0x0) {
              plVar8[2] = 0;
              *plVar16 = *plVar16 + -1;
              if (*plVar16 == 0) {
                (**(code **)(plVar16[1] + 0x30))();
              }
            }
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
            }
            plVar8[0xf] = 0;
            pcVar15 = _Py_NoneStruct_exref;
            *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            lVar12 = *plStack_f8;
            *plStack_f8 = lVar12 + -1;
            if (lVar12 + -1 == 0) {
              (**(code **)(plStack_f8[1] + 0x30))(plStack_f8);
            }
            if ((pcVar14 != (code *)0x0) &&
               (*(longlong *)pcVar14 = *(longlong *)pcVar14 + -1, *(longlong *)pcVar14 == 0)) {
              (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
            }
            if ((plVar27 != (longlong *)0x0) && (*plVar27 = *plVar27 + -1, *plVar27 == 0)) {
              (**(code **)(plVar27[1] + 0x30))(plVar27);
            }
            *plVar2 = *plVar2 + -1;
            if (*plVar2 != 0) {
              return pcVar15;
            }
            (**(code **)(plVar2[1] + 0x30))(plVar2);
            return pcVar15;
          }
          plVar16 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eed8a98);
          if (plVar16 == (longlong *)0x0) {
LAB_23e725338:
            auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_90 = *(code **)(param_1 + 0x68);
            apcStack_88[0] = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (apcStack_88[0] == (code *)0x0) {
              uVar29 = 0x10f;
              goto LAB_23e7250a0;
            }
            pcVar22 = apcStack_88[0];
            if (plVar8 == *(longlong **)(apcStack_88[0] + 0x18)) goto LAB_23e724d00;
            uVar29 = 0x10f;
            pcVar15 = pcVar14;
            goto LAB_23e724fb0;
          }
          *(undefined4 *)(plVar8 + 5) = 0x10f;
          pcVar15 = (code *)FUN_23e91bfe0(param_1,plVar16,DAT_23eed8a98);
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))();
          }
          if (pcVar15 == (code *)0x0) goto LAB_23e725338;
          if ((pcVar14 != (code *)0x0) &&
             (*(longlong *)pcVar14 = *(longlong *)pcVar14 + -1, *(longlong *)pcVar14 == 0)) {
            (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
          }
          pcVar14 = pcVar15;
          if (pcVar15 == _Py_NoneStruct_exref) {
            lVar20 = FUN_23e8e0ba0();
            lVar12 = _DAT_23eed8d48;
            if (lVar20 == 0) {
              FUN_23e915740(param_1,auStack_98,DAT_23eed8c70);
              pcVar14 = _Py_NoneStruct_exref;
            }
            else {
              *(undefined4 *)(plVar8 + 5) = 0x111;
              plVar16 = (longlong *)
                        FUN_23e915840(param_1,lVar20,DAT_23eed8d40,*(undefined8 *)(lVar12 + 0x18));
              if (plVar16 != (longlong *)0x0) {
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  (**(code **)(plVar16[1] + 0x30))();
                }
                goto LAB_23e7241da;
              }
              auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
              pcStack_90 = *(code **)(param_1 + 0x68);
              apcStack_88[0] = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              pcVar14 = _Py_NoneStruct_exref;
            }
            _Py_NoneStruct_exref = pcVar14;
            if (apcStack_88[0] != (code *)0x0) {
              uVar29 = 0x111;
              plVar16 = *(longlong **)(apcStack_88[0] + 0x18);
              goto joined_r0x00023e725924;
            }
            uVar29 = 0x111;
            goto LAB_23e7250a0;
          }
          *(undefined4 *)(plVar8 + 5) = 0x114;
          plVar16 = (longlong *)FUN_23e915840(param_1,plStack_f8,_DAT_23eed8d58,pcVar15);
          if (plVar16 == (longlong *)0x0) {
            auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_90 = *(code **)(param_1 + 0x68);
            apcStack_88[0] = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (apcStack_88[0] == (code *)0x0) {
              uVar29 = 0x114;
              goto LAB_23e7250a0;
            }
            uVar29 = 0x114;
            plVar16 = *(longlong **)(apcStack_88[0] + 0x18);
            goto joined_r0x00023e725924;
          }
          if ((plVar27 != (longlong *)0x0) && (*plVar27 = *plVar27 + -1, *plVar27 == 0)) {
            (**(code **)(plVar27[1] + 0x30))(plVar27);
          }
          plVar17 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eed8ab8);
          plVar27 = plVar16;
          if (plVar17 == (longlong *)0x0) {
            auVar28 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcVar23 = *(code **)(param_1 + 0x68);
            pcVar22 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e725684:
            uVar29 = 0x116;
            apcStack_88[0] = pcVar22;
            auStack_98 = auVar28;
            pcStack_90 = pcVar23;
            if (pcVar22 != (code *)0x0) goto LAB_23e725251;
LAB_23e7256a3:
            uVar29 = 0x116;
            goto LAB_23e7250a0;
          }
          plVar18 = (longlong *)FUN_23e8d9880(plVar17,DAT_23ed6cd90);
          if (plVar18 == (longlong *)0x0) {
LAB_23e725638:
            pcVar22 = *(code **)(param_1 + 0x70);
            auVar28 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcVar23 = *(code **)(param_1 + 0x68);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            apcStack_88[0] = (code *)0x0;
            auStack_98 = (undefined1  [8])0x0;
            pcStack_90 = (code *)0x0;
            *plVar17 = *plVar17 + -1;
            if (*plVar17 == 0) {
              (**(code **)(plVar17[1] + 0x30))();
            }
            goto LAB_23e725684;
          }
          *(undefined4 *)(plVar8 + 5) = 0x116;
          plVar19 = (longlong *)FUN_23e91a870(param_1,plVar18);
          *plVar18 = *plVar18 + -1;
          if (*plVar18 == 0) {
            (**(code **)(plVar18[1] + 0x30))();
          }
          if (plVar19 == (longlong *)0x0) goto LAB_23e725638;
          plVar18 = (longlong *)FUN_23e8d9880(plVar17,DAT_23ed6cd98);
          if (plVar18 == (longlong *)0x0) {
            auVar28 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcVar23 = *(code **)(param_1 + 0x68);
            pcVar22 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            apcStack_88[0] = (code *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            auStack_98 = (undefined1  [8])0x0;
            pcStack_90 = (code *)0x0;
            *plVar17 = *plVar17 + -1;
            if (*plVar17 == 0) {
              iStack_f0 = 0x116;
LAB_23e7254f9:
              apcStack_88[0] = (code *)0x0;
              auStack_98 = (undefined1  [8])0x0;
              pcStack_90 = (code *)0x0;
              (**(code **)(plVar17[1] + 0x30))();
              lVar12 = *plVar19;
              *plVar19 = lVar12 + -1;
              if (lVar12 + -1 == 0) {
LAB_23e7247ff:
                (**(code **)(plVar19[1] + 0x30))();
              }
              if (plVar18 != (longlong *)0x0) goto LAB_23e724824;
            }
            else {
              lVar12 = *plVar19;
              *plVar19 = lVar12 + -1;
              if (lVar12 + -1 != 0) goto LAB_23e725684;
              (**(code **)(plVar19[1] + 0x30))();
              iStack_f0 = 0x116;
            }
LAB_23e72483e:
            apcStack_88[0] = pcVar22;
            auStack_98 = auVar28;
            pcStack_90 = pcVar23;
            if (pcVar22 == (code *)0x0) {
              if (iStack_f0 != 0) goto LAB_23e7256a3;
              uVar29 = (undefined4)plVar8[5];
              goto LAB_23e7250a0;
            }
            if (*(longlong **)(pcVar22 + 0x18) == plVar8) goto LAB_23e724d00;
            if (iStack_f0 == 0) {
              uVar29 = (undefined4)plVar8[5];
            }
            else {
              uVar29 = 0x116;
            }
            goto LAB_23e724fb0;
          }
          cVar10 = FUN_23e8d9ac0(plVar2,DAT_23eed8ac0,plVar16);
          if (cVar10 == '\0') {
            auStack_b8 = *(undefined1 (*) [16])(param_1 + 0x60);
            apcStack_88[0] = (code *)0x0;
            plVar16 = *(longlong **)(param_1 + 0x70);
            plVar3 = *(longlong **)(param_1 + 0x138);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            auStack_98 = (undefined1  [8])0x0;
            pcStack_90 = (code *)0x0;
            if (plVar3 != (longlong *)0x0) {
              *plVar3 = *plVar3 + 1;
            }
            pcVar22 = DAT_23ed6a4f8;
            pcStack_a8 = (code *)plVar16;
            if (plVar16 == (longlong *)0x0) {
              if (DAT_23ed6a4f8 == (code *)0x0) {
                pcVar22 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
              }
              else {
                pcVar23 = *(code **)DAT_23ed6a4f8;
                *(longlong *)DAT_23ed6a4f8 = 1;
                DAT_23ed6a4f8 = pcVar23;
                DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
              }
              *(longlong *)(pcVar22 + 0x10) = 0;
              *(longlong **)(pcVar22 + 0x18) = plVar8;
              *plVar8 = *plVar8 + 1;
              *(longlong *)(pcVar22 + 0x20) = 0x117ffffffff;
              lVar12 = *(longlong *)
                        (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
              lVar20 = *(longlong *)(pcVar22 + -8);
              puVar4 = *(undefined8 **)(lVar12 + 8);
              *puVar4 = pcVar22 + -0x10;
              *(longlong *)(pcVar22 + -0x10) = lVar12;
              *(ulonglong *)(pcVar22 + -8) = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar4;
              *(code **)(lVar12 + 8) = pcVar22 + -0x10;
            }
            else {
              if (DAT_23ed6a4f8 == (code *)0x0) {
                pcVar22 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
              }
              else {
                pcVar23 = *(code **)DAT_23ed6a4f8;
                *(longlong *)DAT_23ed6a4f8 = 1;
                DAT_23ed6a4f8 = pcVar23;
                DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
              }
              *(longlong **)(pcVar22 + 0x18) = plVar8;
              *plVar8 = *plVar8 + 1;
              *(longlong *)(pcVar22 + 0x20) = 0x117ffffffff;
              lVar12 = *(longlong *)
                        (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
              lVar20 = *(longlong *)(pcVar22 + -8);
              puVar4 = *(undefined8 **)(lVar12 + 8);
              *puVar4 = pcVar22 + -0x10;
              *(longlong *)(pcVar22 + -0x10) = lVar12;
              *(ulonglong *)(pcVar22 + -8) = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar4;
              *(code **)(lVar12 + 8) = pcVar22 + -0x10;
              *(longlong **)(pcVar22 + 0x10) = plVar16;
              *plVar16 = *plVar16 + 1;
            }
            if ((pcStack_a8 != (code *)0x0) &&
               (*(longlong *)pcStack_a8 = *(longlong *)pcStack_a8 + -1, *(longlong *)pcStack_a8 == 0
               )) {
              (**(code **)(*(longlong *)((longlong)pcStack_a8 + 8) + 0x30))();
            }
            pcStack_a8 = pcVar22;
            if (((code *)auStack_b8._0_8_ != _Py_NoneStruct_exref) &&
               ((code *)auStack_b8._0_8_ != (code *)0x0)) {
              FUN_23e91b1b0(param_1,auStack_b8,auStack_b8 + 8);
            }
            plVar16 = *(longlong **)(auStack_b8._8_8_ + 0x28);
            if (pcStack_a8 == _Py_NoneStruct_exref) {
              pcVar22 = (code *)0x0;
            }
            else {
              pcVar22 = pcStack_a8;
              if (pcStack_a8 != (code *)0x0) {
                *(longlong *)pcStack_a8 = *(longlong *)pcStack_a8 + 1;
              }
            }
            *(code **)(auStack_b8._8_8_ + 0x28) = pcVar22;
            if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
              (**(code **)(plVar16[1] + 0x30))();
            }
            plVar16 = *(longlong **)(param_1 + 0x138);
            *(undefined8 *)(param_1 + 0x138) = auStack_b8._8_8_;
            if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
              (**(code **)(plVar16[1] + 0x30))();
            }
            *(longlong *)auStack_b8._0_8_ = *(longlong *)auStack_b8._0_8_ + -1;
            if (*(longlong *)auStack_b8._0_8_ == 0) {
              (**(code **)(*(longlong *)(auStack_b8._0_8_ + 8) + 0x30))();
            }
            if ((pcStack_a8 != (code *)0x0) &&
               (*(longlong *)pcStack_a8 = *(longlong *)pcStack_a8 + -1, *(longlong *)pcStack_a8 == 0
               )) {
              (**(code **)(*(longlong *)(pcStack_a8 + 8) + 0x30))();
            }
            pcVar23 = *(code **)(param_1 + 0x138);
            pcStack_a8 = (code *)0x0;
            auStack_b8 = (undefined1  [16])0x0;
            pcVar22 = *(code **)PyExc_BaseException_exref;
            pcVar24 = *(code **)(pcVar23 + 8);
            if ((*(uint *)(*(longlong *)(pcVar22 + 8) + 0xa8) & 0x4000000) != 0) {
              lVar12 = *(longlong *)(pcVar22 + 0x10);
              if (0 < lVar12) {
                lVar20 = 0;
                do {
                  if ((-1 < *(int *)(*(longlong *)(*(longlong *)(pcVar22 + lVar20 * 8 + 0x18) + 8) +
                                    0xa8)) ||
                     ((*(byte *)(*(longlong *)(pcVar22 + lVar20 * 8 + 0x18) + 0xab) & 0x40) == 0))
                  goto LAB_23e7249a8;
                  lVar20 = lVar20 + 1;
                } while (lVar12 != lVar20);
                lVar20 = 0;
                while (iVar11 = FUN_23a35ebd0(param_1,pcVar24,
                                              *(undefined8 *)(pcVar22 + lVar20 * 8 + 0x18)),
                      iVar11 == 0) {
                  lVar20 = lVar20 + 1;
                  if (lVar12 == lVar20) {
                    pcVar23 = *(code **)(param_1 + 0x138);
                    goto LAB_23e7246a6;
                  }
                }
LAB_23e724a19:
                pcVar23 = *(code **)(param_1 + 0x138);
                goto LAB_23e724a20;
              }
              goto LAB_23e7246a6;
            }
            if (((int)*(uint *)(*(longlong *)(pcVar22 + 8) + 0xa8) < 0) &&
               (((byte)pcVar22[0xab] & 0x40) != 0)) {
              pcVar26 = *(code **)(pcVar24 + 8);
              if ((*(uint *)(pcVar26 + 0xa8) & 0x40000000) == 0) {
                pcVar25 = pcVar24;
                if ((-1 < (int)*(uint *)(pcVar26 + 0xa8)) ||
                   (pcVar26 = pcVar24, ((byte)pcVar24[0xab] & 0x40) == 0)) goto LAB_23e725406;
              }
              else {
                pcVar25 = pcVar26;
                if (-1 < *(int *)(*(longlong *)(pcVar26 + 8) + 0xa8)) {
LAB_23e725406:
                  if (pcVar25 != pcVar22) goto LAB_23e7246a6;
                  goto LAB_23e724a24;
                }
              }
              lVar12 = *(longlong *)(pcVar26 + 0x158);
              if (lVar12 == 0) {
                do {
                  if (pcVar22 == pcVar26) goto LAB_23e724a20;
                  pcVar26 = *(code **)(pcVar26 + 0x100);
                } while (pcVar26 != (code *)0x0);
                if (pcVar22 == PyBaseObject_Type_exref) goto LAB_23e724a20;
              }
              else if (0 < *(longlong *)(lVar12 + 0x10)) {
                lVar20 = 0;
                while (pcVar22 != *(code **)(lVar12 + 0x18 + lVar20 * 8)) {
                  lVar20 = lVar20 + 1;
                  if (*(longlong *)(lVar12 + 0x10) == lVar20) goto LAB_23e7246a6;
                }
LAB_23e724a20:
                pcVar24 = *(code **)(pcVar23 + 8);
                goto LAB_23e724a24;
              }
LAB_23e7246a6:
              pcStack_90 = pcVar23;
              if ((pcVar23 == _Py_NoneStruct_exref) || (pcVar23 == (code *)0x0)) {
                bVar9 = true;
                auVar28 = *(undefined1 (*) [8])PyExc_RuntimeError_exref;
                pcVar23 = (code *)PyUnicode_FromString("No active exception to reraise");
                pcVar22 = (code *)0x0;
                pcVar24 = *(code **)(param_1 + 0x138);
                *(longlong *)auVar28 = *(longlong *)auVar28 + 1;
                goto LAB_23e7258a3;
              }
              auVar28 = *(undefined1 (*) [8])(pcVar23 + 8);
              pcVar22 = *(code **)(pcVar23 + 0x28);
              *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
              *(longlong *)auVar28 = *(longlong *)auVar28 + 1;
              if (pcVar22 == (code *)0x0) {
                iStack_f0 = 0;
                bVar9 = true;
                *(longlong **)(param_1 + 0x138) = plVar3;
                pcVar24 = pcVar23;
              }
              else {
                *(longlong *)pcVar22 = *(longlong *)pcVar22 + 1;
                if (*(longlong **)(pcVar22 + 0x18) == plVar8) {
                  *(undefined4 *)(plVar8 + 5) = *(undefined4 *)(pcVar22 + 0x24);
                }
                bVar9 = true;
LAB_23e7246fc:
                iStack_f0 = 0;
                *(longlong **)(param_1 + 0x138) = plVar3;
                pcVar24 = pcVar23;
              }
LAB_23e724728:
              apcStack_88[0] = (code *)0x0;
              _auStack_98 = (undefined1  [16])0x0;
              *(longlong *)pcVar24 = *(longlong *)pcVar24 + -1;
              if (*(longlong *)pcVar24 == 0) {
                (**(code **)(*(longlong *)(pcVar24 + 8) + 0x30))();
              }
            }
            else {
LAB_23e7249a8:
              plVar16 = *(longlong **)PyExc_TypeError_exref;
              uVar21 = PyUnicode_FromString
                                 (
                                 "catching classes that do not inherit from BaseException is not allowed"
                                 );
              plVar5 = *(longlong **)(param_1 + 0x60);
              plVar6 = *(longlong **)(param_1 + 0x68);
              plVar7 = *(longlong **)(param_1 + 0x70);
              *(longlong **)(param_1 + 0x60) = plVar16;
              *plVar16 = *plVar16 + 1;
              *(undefined8 *)(param_1 + 0x68) = uVar21;
              *(undefined8 *)(param_1 + 0x70) = 0;
              if ((plVar5 != (longlong *)0x0) && (*plVar5 = *plVar5 + -1, *plVar5 == 0)) {
                (**(code **)(plVar5[1] + 0x30))();
              }
              if ((plVar6 != (longlong *)0x0) && (*plVar6 = *plVar6 + -1, *plVar6 == 0)) {
                (**(code **)(plVar6[1] + 0x30))(plVar6);
              }
              if ((plVar7 == (longlong *)0x0) || (*plVar7 = *plVar7 + -1, *plVar7 != 0))
              goto LAB_23e724a19;
              (**(code **)(plVar7[1] + 0x30))(plVar7);
              pcVar23 = *(code **)(param_1 + 0x138);
              pcVar24 = *(code **)(pcVar23 + 8);
LAB_23e724a24:
              pcStack_68 = *(code **)(pcVar23 + 0x28);
              *(undefined4 *)(plVar8 + 5) = 0x116;
              if (pcStack_68 == (code *)0x0) {
                pcStack_68 = _Py_NoneStruct_exref;
              }
              pcStack_78 = pcVar24;
              pcStack_70 = pcVar23;
              plVar16 = (longlong *)FUN_23e956150(param_1,plVar18,&pcStack_78);
              if (plVar16 != (longlong *)0x0) {
                iVar11 = FUN_23a35f020(plVar16);
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  (**(code **)(plVar16[1] + 0x30))();
                }
                if (iVar11 != -1) {
                  if (iVar11 != 0) {
                    plVar16 = *(longlong **)(param_1 + 0x138);
                    *(longlong **)(param_1 + 0x138) = plVar3;
                    if (plVar16 != (longlong *)0x0) goto LAB_23e724abb;
                    goto LAB_23e724ac8;
                  }
                  pcVar23 = *(code **)(param_1 + 0x138);
                  pcStack_90 = pcVar23;
                  bVar9 = false;
                  if ((pcVar23 == _Py_NoneStruct_exref) || (pcVar23 == (code *)0x0)) {
                    auVar28 = *(undefined1 (*) [8])PyExc_RuntimeError_exref;
                    pcVar23 = (code *)PyUnicode_FromString("No active exception to reraise");
                    pcVar22 = (code *)0x0;
                    pcVar24 = *(code **)(param_1 + 0x138);
                    *(longlong *)auVar28 = *(longlong *)auVar28 + 1;
                    goto LAB_23e7258a3;
                  }
                  auVar28 = *(undefined1 (*) [8])(pcVar23 + 8);
                  pcVar22 = *(code **)(pcVar23 + 0x28);
                  *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
                  *(longlong *)auVar28 = *(longlong *)auVar28 + 1;
                  if (pcVar22 != (code *)0x0) {
                    *(longlong *)pcVar22 = *(longlong *)pcVar22 + 1;
                    if (*(longlong **)(pcVar22 + 0x18) == plVar8) {
                      *(undefined4 *)(plVar8 + 5) = *(undefined4 *)(pcVar22 + 0x24);
                    }
                    goto LAB_23e7246fc;
                  }
                  iStack_f0 = 0;
                  *(longlong **)(param_1 + 0x138) = plVar3;
                  pcVar24 = pcVar23;
                  goto LAB_23e724728;
                }
              }
              pcVar22 = *(code **)(param_1 + 0x70);
              pcVar24 = *(code **)(param_1 + 0x138);
              auVar28 = *(undefined1 (*) [8])(param_1 + 0x60);
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcVar23 = *(code **)(param_1 + 0x68);
              bVar9 = false;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e7258a3:
              iStack_f0 = 0x116;
              *(longlong **)(param_1 + 0x138) = plVar3;
              if (pcVar24 != (code *)0x0) goto LAB_23e724728;
            }
            apcStack_88[0] = (code *)0x0;
            _auStack_98 = (undefined1  [16])0x0;
            pcStack_78 = (code *)auVar28;
            pcStack_70 = pcVar23;
            pcStack_68 = pcVar22;
            if (bVar9) {
              *(undefined4 *)(plVar8 + 5) = 0x116;
              plVar16 = (longlong *)FUN_23e957a30(param_1,plVar18,DAT_23eed8d60);
              if (plVar16 == (longlong *)0x0) {
                apcStack_88[0] = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
                pcStack_90 = *(code **)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                FUN_23a35d6b0();
                iStack_f0 = 0x116;
                pcVar22 = apcStack_88[0];
                auVar28 = auStack_98;
                pcVar23 = pcStack_90;
              }
              else {
                *plVar16 = *plVar16 + -1;
                pcVar22 = pcStack_68;
                auVar28 = (undefined1  [8])pcStack_78;
                pcVar23 = pcStack_70;
                if (*plVar16 == 0) {
                  (**(code **)(plVar16[1] + 0x30))();
                  pcVar22 = pcStack_68;
                  auVar28 = (undefined1  [8])pcStack_78;
                  pcVar23 = pcStack_70;
                }
              }
            }
LAB_23e7247c7:
            apcStack_88[0] = (code *)0x0;
            auStack_98 = (undefined1  [8])0x0;
            pcStack_90 = (code *)0x0;
            *plVar17 = *plVar17 + -1;
            if (*plVar17 == 0) goto LAB_23e7254f9;
            lVar12 = *plVar19;
            *plVar19 = lVar12 + -1;
            if (lVar12 + -1 == 0) goto LAB_23e7247ff;
LAB_23e724824:
            *plVar18 = *plVar18 + -1;
            if (*plVar18 == 0) {
              (**(code **)(plVar18[1] + 0x30))();
            }
            goto LAB_23e72483e;
          }
          *(undefined4 *)(plVar8 + 5) = 0x116;
          plVar16 = (longlong *)FUN_23e957a30(param_1,plVar18,DAT_23eed8d60);
          if (plVar16 == (longlong *)0x0) {
            auVar28 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcVar23 = *(code **)(param_1 + 0x68);
            pcVar22 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            iStack_f0 = 0x116;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e7247c7;
          }
LAB_23e724abb:
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))();
          }
LAB_23e724ac8:
          *plVar17 = *plVar17 + -1;
          if (*plVar17 == 0) {
            (**(code **)(plVar17[1] + 0x30))();
          }
          *plVar19 = *plVar19 + -1;
          if (*plVar19 == 0) {
            (**(code **)(plVar19[1] + 0x30))();
          }
          *plVar18 = *plVar18 + -1;
          if (*plVar18 == 0) {
            (**(code **)(plVar18[1] + 0x30))();
          }
          lVar12 = *(longlong *)(param_1 + 0x10);
          if ((((*(int *)(*(longlong *)(lVar12 + 0x28) + 0x160) != 0) ||
               (*(int *)(lVar12 + 0x78) != 0)) && (iVar11 = Py_MakePendingCalls(), iVar11 < 0)) &&
             (pcVar23 = *(code **)(param_1 + 0x60), pcVar23 != (code *)0x0)) goto LAB_23e725215;
          if (*(int *)(lVar12 + 0x68) != 0) {
            PyEval_SaveThread();
            PyEval_AcquireThread(param_1);
          }
          plVar16 = *(longlong **)(param_1 + 0x90);
        } while (plVar16 == (longlong *)0x0);
        plVar17 = *(longlong **)(param_1 + 0x60);
        plVar18 = *(longlong **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x90) = 0;
        plVar19 = *(longlong **)(param_1 + 0x70);
        *(longlong **)(param_1 + 0x60) = plVar16;
        *plVar16 = *plVar16 + 1;
        *(undefined8 *)(param_1 + 0x68) = 0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
          (**(code **)(plVar17[1] + 0x30))();
        }
        if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
          (**(code **)(plVar18[1] + 0x30))();
        }
        if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
          (**(code **)(plVar19[1] + 0x30))();
        }
        pcVar23 = *(code **)(param_1 + 0x60);
LAB_23e725215:
        pcVar22 = *(code **)(param_1 + 0x70);
        uVar29 = 0x10e;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_90 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        apcStack_88[0] = pcVar22;
        auStack_98 = (undefined1  [8])pcVar23;
        if (pcVar22 != (code *)0x0) {
LAB_23e725251:
          plVar16 = *(longlong **)(pcVar22 + 0x18);
          apcStack_88[0] = pcVar22;
joined_r0x00023e725924:
          pcVar22 = apcStack_88[0];
          if (plVar8 == plVar16) goto LAB_23e724d00;
          goto LAB_23e724fb0;
        }
      }
    }
    else {
      iVar11 = *(int *)(lVar12 + 0xc);
      if (*(int *)(lVar12 + 0xc) == 0) {
        *(int *)(lVar12 + 0xc) = DAT_23ec1545c;
        iVar11 = DAT_23ec1545c;
        DAT_23ec1545c = DAT_23ec1545c + 1;
      }
      if (_DAT_23ec1544c != iVar11) {
        _DAT_23ec1544c = iVar11;
        _DAT_23eedae70 = FUN_23e8cbd60(lVar12,_DAT_23eed8d28,*(undefined8 *)(_DAT_23eed8d28 + 0x18))
        ;
      }
      if (-1 < _DAT_23eedae70) {
        lVar1 = lVar12 + 0x20 + (1L << (*(byte *)(lVar12 + 9) & 0x3f));
        lVar20 = *(longlong *)(lVar1 + 8 + _DAT_23eedae70 * 0x10);
        if (lVar20 != 0) goto LAB_23e724133;
        _DAT_23eedae70 = FUN_23e8cbd60(lVar12,_DAT_23eed8d28,*(undefined8 *)(_DAT_23eed8d28 + 0x18))
        ;
        if (-1 < _DAT_23eedae70) {
          lVar20 = *(longlong *)(lVar1 + 8 + _DAT_23eedae70 * 0x10);
          goto LAB_23e725298;
        }
      }
LAB_23e7248a9:
      plVar27 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eed8d28);
      if ((plVar27 != (longlong *)0x0) && (lVar20 = *plVar27, lVar20 != 0)) goto LAB_23e724133;
      FUN_23e915740(param_1,auStack_98,_DAT_23eed8d28);
      if (apcStack_88[0] != (code *)0x0) {
        if (plVar8 != *(longlong **)(apcStack_88[0] + 0x18)) {
          plStack_f8 = (longlong *)0x0;
          plVar27 = (longlong *)0x0;
          uVar29 = 0x10c;
          pcVar15 = (code *)0x0;
          goto LAB_23e724fb0;
        }
        goto LAB_23e724cec;
      }
LAB_23e725540:
      plStack_f8 = (longlong *)0x0;
      plVar27 = (longlong *)0x0;
      pcVar14 = (code *)0x0;
      uVar29 = 0x10c;
    }
LAB_23e7250a0:
    pcVar22 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar22 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      pcVar15 = apcStack_88[0];
    }
    else {
      pcVar15 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar15;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      pcVar15 = (code *)0x0;
    }
    pcVar23 = _PyRuntime_exref;
    *(longlong *)(pcVar22 + 0x10) = 0;
    *(longlong **)(pcVar22 + 0x18) = plVar8;
    *plVar8 = *plVar8 + 1;
    lVar12 = *(longlong *)(pcVar23 + 0x1f8);
    *(undefined4 *)(pcVar22 + 0x20) = 0xffffffff;
    lVar12 = *(longlong *)(lVar12 + 0x10);
    *(undefined4 *)(pcVar22 + 0x24) = uVar29;
    lVar12 = *(longlong *)(lVar12 + 0x2e8);
    lVar20 = *(longlong *)(pcVar22 + -8);
    puVar4 = *(undefined8 **)(lVar12 + 8);
    *puVar4 = pcVar22 + -0x10;
    *(longlong *)(pcVar22 + -0x10) = lVar12;
    *(ulonglong *)(pcVar22 + -8) = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar4;
    *(code **)(lVar12 + 8) = pcVar22 + -0x10;
  }
  if ((pcVar15 != (code *)0x0) &&
     (*(longlong *)pcVar15 = *(longlong *)pcVar15 + -1, *(longlong *)pcVar15 == 0)) {
    (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))();
  }
LAB_23e724d00:
  apcStack_88[0] = pcVar22;
  FUN_23e8bba40(plVar8,"ooooo",plVar2,plVar13,plStack_f8,pcVar14,plVar27);
  if (_DAT_23eedae78 == plVar8) {
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    _DAT_23eedae78 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar8 = *(longlong **)(lVar12 + 0x28);
  plVar16 = (longlong *)plVar8[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  *(undefined4 *)(plVar8 + 8) = 0xffffffff;
  if (plVar16 != (longlong *)0x0) {
    plVar8[2] = 0;
    *plVar16 = *plVar16 + -1;
    if (*plVar16 == 0) {
      (**(code **)(plVar16[1] + 0x30))();
    }
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  pcVar22 = apcStack_88[0];
  pcVar15 = pcStack_90;
  auVar28 = auStack_98;
  plVar8[0xf] = 0;
  _auStack_98 = (undefined1  [16])0x0;
  apcStack_88[0] = (code *)0x0;
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((plStack_f8 != (longlong *)0x0) &&
     (lVar12 = *plStack_f8, *plStack_f8 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_f8[1] + 0x30))(plStack_f8);
  }
  if ((pcVar14 != (code *)0x0) &&
     (*(longlong *)pcVar14 = *(longlong *)pcVar14 + -1, *(longlong *)pcVar14 == 0)) {
    (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
  }
  if ((plVar27 != (longlong *)0x0) && (*plVar27 = *plVar27 + -1, *plVar27 == 0)) {
    (**(code **)(plVar27[1] + 0x30))(plVar27);
  }
  *plVar2 = *plVar2 + -1;
  apcStack_88[0] = pcVar22;
  auStack_98 = auVar28;
  pcStack_90 = pcVar15;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,auStack_98,pcStack_90,apcStack_88[0]);
  return (code *)0x0;
}
