/* ===== 23c65bd40 license.hwid_generator:22 ===== */
/* ghidra_name=FUN_23c65bd40 entry=23c65bd40 size=9949 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23c65bd40(longlong param_1)

{
  code *pcVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  code *pcVar4;
  bool bVar5;
  int iVar6;
  char cVar7;
  int iVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong lVar17;
  longlong *plVar18;
  longlong *plVar19;
  code *pcVar20;
  undefined8 uVar21;
  code *pcVar22;
  code *pcVar23;
  undefined4 uVar24;
  undefined1 auVar25 [8];
  code *pcVar26;
  longlong *plStack_128;
  longlong *plStack_120;
  longlong *plStack_110;
  undefined1 auStack_f8 [16];
  code *apcStack_e8 [2];
  longlong *plStack_d8;
  code *pcStack_d0;
  code *pcStack_c8;
  undefined1 auStack_b8 [16];
  code *apcStack_a8 [2];
  undefined1 auStack_98 [8];
  code *pcStack_90;
  code *pcStack_88;
  longlong *plStack_78;
  longlong lStack_70;
  code *pcStack_68;
  longlong *plStack_60;
  
  plVar10 = _DAT_23ee29da0;
  pcStack_88 = (code *)0x0;
  auStack_98 = (undefined1  [8])0x0;
  pcStack_90 = (code *)0x0;
  if (_DAT_23ee29da0 == (longlong *)0x0) {
LAB_23c65bd9a:
    _DAT_23ee29da0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23ee29d90,_DAT_23ee29d98,0x28);
  }
  else {
    lVar9 = *_DAT_23ee29da0;
    if (1 < lVar9) {
      *_DAT_23ee29da0 = lVar9 + -1;
      goto LAB_23c65bd9a;
    }
    if (_DAT_23ee29da0[2] != 0) {
      *_DAT_23ee29da0 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23c65bd9a;
    }
  }
  plVar3 = _DAT_23ee29da0;
  lVar9 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23ee29da0 + 9;
  lVar17 = *(longlong *)(lVar9 + 8);
  _DAT_23ee29da0[0xf] = lVar17;
  *(longlong **)(lVar9 + 8) = plVar10;
  if ((lVar17 != 0) &&
     (((*(char *)(lVar17 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar17 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar17 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar17 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar17 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  lVar9 = FUN_23ead6720();
  if (lVar9 == 0) {
    FUN_23e915740(param_1,auStack_98,_DAT_23ee28c60);
    if (pcStack_88 == (code *)0x0) goto LAB_23c65d580;
LAB_23c65d3ca:
    plVar10 = (longlong *)0x0;
    if (plVar3 != *(longlong **)(pcStack_88 + 0x18)) {
      plStack_120 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      iVar8 = 0x19;
      plStack_128 = (longlong *)0x0;
      goto LAB_23c65c5a9;
    }
    goto LAB_23c65c680;
  }
  plVar10 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23ee28c68);
  if (plVar10 == (longlong *)0x0) {
    auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcStack_90 = *(code **)(param_1 + 0x68);
    pcStack_88 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (pcStack_88 != (code *)0x0) goto LAB_23c65d3ca;
LAB_23c65d580:
    plStack_120 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    iVar8 = 0x19;
LAB_23c65d59f:
    pcVar22 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar22 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      pcVar23 = pcStack_88;
    }
    else {
      pcVar23 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar23;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      pcVar23 = (code *)0x0;
    }
    pcVar26 = _PyRuntime_exref;
    *(longlong **)(pcVar22 + 0x18) = plVar3;
    *(longlong *)(pcVar22 + 0x10) = 0;
    *plVar3 = *plVar3 + 1;
    lVar9 = *(longlong *)(pcVar26 + 0x1f8);
    *(undefined4 *)(pcVar22 + 0x20) = 0xffffffff;
    lVar9 = *(longlong *)(lVar9 + 0x10);
    *(int *)(pcVar22 + 0x24) = iVar8;
    lVar9 = *(longlong *)(lVar9 + 0x2e8);
    lVar17 = *(longlong *)(pcVar22 + -8);
    puVar2 = *(undefined8 **)(lVar9 + 8);
    *puVar2 = pcVar22 + -0x10;
    *(longlong *)(pcVar22 + -0x10) = lVar9;
    *(ulonglong *)(pcVar22 + -8) = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar2;
    *(code **)(lVar9 + 8) = pcVar22 + -0x10;
  }
  else {
    lVar9 = FUN_23ead6720();
    if (lVar9 == 0) {
      FUN_23e915740(param_1,auStack_98,_DAT_23ee28c60);
      *plVar10 = *plVar10 + -1;
      if (*plVar10 != 0) goto joined_r0x00023c65d675;
      (**(code **)(plVar10[1] + 0x30))();
      if (pcStack_88 == (code *)0x0) goto LAB_23c65d580;
      plVar10 = *(longlong **)(pcStack_88 + 0x18);
joined_r0x00023c65dc42:
      if (plVar3 == plVar10) {
LAB_23c65c680:
        plStack_120 = (longlong *)0x0;
        plStack_110 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        pcVar22 = pcStack_88;
        goto LAB_23c65c699;
      }
      plVar11 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      iVar8 = 0x19;
      plStack_128 = (longlong *)0x0;
    }
    else {
      plVar11 = (longlong *)FUN_23e8bbbe0(param_1,lVar9,_DAT_23ee28c70,DAT_23ed6ccf0);
      if (plVar11 == (longlong *)0x0) {
        auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_90 = *(code **)(param_1 + 0x68);
        pcStack_88 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))();
        }
joined_r0x00023c65d675:
        if (pcStack_88 == (code *)0x0) goto LAB_23c65d580;
        plVar10 = *(longlong **)(pcStack_88 + 0x18);
        goto joined_r0x00023c65dc42;
      }
      lVar9 = FUN_23e8c1360(plVar10,plVar11);
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))();
      }
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))();
      }
      if (lVar9 == 0) {
        auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_90 = *(code **)(param_1 + 0x68);
        pcStack_88 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (pcStack_88 == (code *)0x0) goto LAB_23c65d580;
        if (plVar3 != *(longlong **)(pcStack_88 + 0x18)) {
          plStack_120 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          iVar8 = 0x19;
          plStack_128 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          goto LAB_23c65c5a9;
        }
        goto LAB_23c65c680;
      }
      plVar10 = (longlong *)FUN_23e8d6340(*(undefined8 *)(param_1 + 0x10),3);
      *(longlong *)plVar10[3] = lVar9;
      lVar9 = FUN_23ead6720();
      if (lVar9 == 0) {
        FUN_23e915740(param_1,auStack_98,_DAT_23ee28c60);
LAB_23c65d4c9:
        iVar8 = 0x1a;
LAB_23c65c560:
        *plVar10 = *plVar10 + -1;
        if (*plVar10 != 0) {
          if (pcStack_88 == (code *)0x0) {
LAB_23c65de44:
            plStack_120 = (longlong *)0x0;
            plStack_110 = (longlong *)0x0;
            plVar11 = (longlong *)0x0;
            plVar10 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            goto LAB_23c65d59f;
          }
          if (*(longlong **)(pcStack_88 + 0x18) == plVar3) goto LAB_23c65c680;
LAB_23c65c590:
          plStack_120 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          goto LAB_23c65c5a9;
        }
        (**(code **)(plVar10[1] + 0x30))();
        if (pcStack_88 == (code *)0x0) goto LAB_23c65de44;
        if (plVar3 != *(longlong **)(pcStack_88 + 0x18)) goto LAB_23c65c590;
        goto LAB_23c65c680;
      }
      plVar11 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23ee28c68);
      if (plVar11 == (longlong *)0x0) {
LAB_23c65d4a0:
        pcStack_88 = *(code **)(param_1 + 0x70);
        auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_90 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23c65d4c9;
      }
      lVar9 = FUN_23ead6720();
      if (lVar9 == 0) {
        FUN_23e915740(param_1,auStack_98,_DAT_23ee28c60);
        *plVar11 = *plVar11 + -1;
        lVar9 = *plVar11;
joined_r0x00023c65ddf9:
        if (lVar9 == 0) {
          (**(code **)(plVar11[1] + 0x30))();
        }
        goto LAB_23c65d4c9;
      }
      plVar12 = (longlong *)FUN_23e8bbbe0(param_1,lVar9,_DAT_23ee28c78,DAT_23ed6ccf0);
      if (plVar12 == (longlong *)0x0) {
        auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_90 = *(code **)(param_1 + 0x68);
        pcStack_88 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar11 = *plVar11 + -1;
        lVar9 = *plVar11;
        goto joined_r0x00023c65ddf9;
      }
      lVar9 = FUN_23e8c1360(plVar11,plVar12);
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))();
      }
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))();
      }
      if (lVar9 == 0) goto LAB_23c65d4a0;
      *(longlong *)(plVar10[3] + 8) = lVar9;
      lVar9 = FUN_23ead6720();
      if (lVar9 == 0) {
        FUN_23e915740(param_1,auStack_98,_DAT_23ee28c60);
LAB_23c65c553:
        iVar8 = 0x1b;
        goto LAB_23c65c560;
      }
      lVar9 = FUN_23e8bc2f0(lVar9,_DAT_23ee28c68);
      if (lVar9 == 0) {
        pcStack_88 = *(code **)(param_1 + 0x70);
        auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_90 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23c65c553;
      }
      *(longlong *)(plVar10[3] + 0x10) = lVar9;
      plVar12 = (longlong *)FUN_23ebf7180();
      if (plVar12 == (longlong *)0x0) {
        auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_90 = *(code **)(param_1 + 0x68);
        pcStack_88 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (pcStack_88 == (code *)0x0) {
          plStack_120 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          iVar8 = 0x1e;
          plStack_128 = (longlong *)0x0;
          goto LAB_23c65d59f;
        }
        iVar8 = 0x1e;
        plVar11 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_110 = (longlong *)0x0;
        pcVar22 = pcStack_88;
        if (plVar3 == *(longlong **)(pcStack_88 + 0x18)) goto LAB_23c65c699;
      }
      else {
        plStack_120 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_110 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
LAB_23c65bfe0:
        do {
          plVar13 = (longlong *)(**(code **)(plVar12[1] + 0xe0))();
          if (plVar13 == (longlong *)0x0) {
            cVar7 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
            if (cVar7 == '\0') {
              pcVar22 = *(code **)(param_1 + 0x70);
              plVar14 = *(longlong **)(param_1 + 0x60);
              pcVar23 = *(code **)(param_1 + 0x68);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              iVar8 = 0x1e;
              pcStack_88 = (code *)0x0;
              _auStack_98 = (undefined1  [16])0x0;
              if (plVar11 == (longlong *)0x0) goto LAB_23c65cf08;
              iVar8 = 0x1e;
              plVar13 = plVar11;
              goto LAB_23c65cef8;
            }
            if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            lVar9 = *plVar12;
            *plVar12 = lVar9 + -1;
            if (lVar9 + -1 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            lVar17 = FUN_23ead6850();
            lVar9 = _DAT_23ee28cc8;
            if (lVar17 != 0) {
              *(undefined4 *)(plVar3 + 5) = 0x2c;
              plVar12 = (longlong *)
                        FUN_23e915840(param_1,lVar17,_DAT_23ee28cc0,*(undefined8 *)(lVar9 + 0x18));
              if (plVar12 != (longlong *)0x0) {
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  (**(code **)(plVar12[1] + 0x30))();
                }
                lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                plVar3 = *(longlong **)(lVar9 + 0x28);
                plVar12 = (longlong *)plVar3[2];
                *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
                *(undefined4 *)(plVar3 + 8) = 0xffffffff;
                if (plVar12 != (longlong *)0x0) {
                  plVar3[2] = 0;
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))();
                  }
                }
                *plVar3 = *plVar3 + -1;
                if (*plVar3 == 0) {
                  (**(code **)(plVar3[1] + 0x30))(plVar3);
                }
                plVar14 = _DAT_23ee28cd0;
                plVar3[0xf] = 0;
                *plVar14 = *plVar14 + 1;
                *plVar10 = *plVar10 + -1;
                if (*plVar10 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                }
                plVar13 = plVar11;
                plVar16 = plStack_110;
                if (plVar11 != (longlong *)0x0) {
LAB_23c65d8ca:
                  *plVar13 = *plVar13 + -1;
                  plVar16 = plStack_110;
                  if (*plVar13 == 0) {
LAB_23c65d8d1:
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                  }
                }
                if (plVar16 == (longlong *)0x0) goto LAB_23c65d906;
LAB_23c65d8eb:
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                }
LAB_23c65d906:
                if ((plStack_128 != (longlong *)0x0) &&
                   (lVar9 = *plStack_128, *plStack_128 = lVar9 + -1, lVar9 + -1 == 0)) {
                  (**(code **)(plStack_128[1] + 0x30))(plStack_128);
                }
                if (plStack_120 == (longlong *)0x0) {
                  return plVar14;
                }
                lVar9 = *plStack_120;
                *plStack_120 = lVar9 + -1;
                if (lVar9 + -1 != 0) {
                  return plVar14;
                }
                (**(code **)(plStack_120[1] + 0x30))(plStack_120);
                return plVar14;
              }
              auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
              pcStack_90 = *(code **)(param_1 + 0x68);
              pcStack_88 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (pcStack_88 == (code *)0x0) goto LAB_23c65e314;
              pcVar22 = pcStack_88;
              if (plVar3 != *(longlong **)(pcStack_88 + 0x18)) goto LAB_23c65dd0d;
              goto LAB_23c65c699;
            }
            FUN_23e915740(param_1,auStack_98,_DAT_23ee28cb8);
            if (pcStack_88 == (code *)0x0) {
LAB_23c65e314:
              iVar8 = 0x2c;
              goto LAB_23c65d59f;
            }
            pcVar22 = pcStack_88;
            if (*(longlong **)(pcStack_88 + 0x18) == plVar3) goto LAB_23c65c699;
LAB_23c65dd0d:
            iVar8 = 0x2c;
            goto LAB_23c65c5a9;
          }
          if (plVar11 != (longlong *)0x0) {
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
              lVar9 = *plVar13;
            }
            else {
              lVar9 = *plVar13;
            }
            *plVar13 = lVar9 + 1;
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            lVar9 = FUN_23ead6720();
            if (lVar9 != 0) goto LAB_23c65c047;
LAB_23c65d0a5:
            iVar8 = 0x20;
            FUN_23e915740(param_1,auStack_98,_DAT_23ee28c60);
            pcVar22 = pcStack_88;
            pcVar26 = _Py_NoneStruct_exref;
            auVar25 = auStack_98;
            pcVar23 = pcStack_90;
LAB_23c65cc7e:
            plVar11 = *(longlong **)(param_1 + 0x138);
            pcStack_88 = (code *)0x0;
            auStack_f8._8_8_ = pcVar23;
            auStack_f8._0_8_ = auVar25;
            auStack_98 = (undefined1  [8])0x0;
            pcStack_90 = (code *)0x0;
            if (plVar11 != (longlong *)0x0) {
              *plVar11 = *plVar11 + 1;
            }
            pcVar23 = DAT_23ed6a4f8;
            apcStack_e8[0] = pcVar22;
            if (pcVar22 == (code *)0x0) {
              if (iVar8 == 0) {
                iVar8 = (int)plVar3[5];
              }
              if (DAT_23ed6a4f8 == (code *)0x0) {
                pcVar23 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
              }
              else {
                pcVar22 = *(code **)DAT_23ed6a4f8;
                *(longlong *)DAT_23ed6a4f8 = 1;
                DAT_23ed6a4f8 = pcVar22;
                DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
              }
              pcVar22 = _PyRuntime_exref;
              *(longlong *)(pcVar23 + 0x10) = 0;
              *(longlong **)(pcVar23 + 0x18) = plVar3;
              *plVar3 = *plVar3 + 1;
              lVar9 = *(longlong *)(pcVar22 + 0x1f8);
              *(undefined4 *)(pcVar23 + 0x20) = 0xffffffff;
              lVar9 = *(longlong *)(lVar9 + 0x10);
              *(int *)(pcVar23 + 0x24) = iVar8;
              lVar9 = *(longlong *)(lVar9 + 0x2e8);
              lVar17 = *(longlong *)(pcVar23 + -8);
              puVar2 = *(undefined8 **)(lVar9 + 8);
              *puVar2 = pcVar23 + -0x10;
              *(longlong *)(pcVar23 + -0x10) = lVar9;
              *(ulonglong *)(pcVar23 + -8) = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar2;
              *(code **)(lVar9 + 8) = pcVar23 + -0x10;
joined_r0x00023c65d28f:
              pcVar22 = pcVar23;
              if ((apcStack_e8[0] != (code *)0x0) &&
                 (*(longlong *)apcStack_e8[0] = *(longlong *)apcStack_e8[0] + -1,
                 *(longlong *)apcStack_e8[0] == 0)) {
                (**(code **)(*(longlong *)(apcStack_e8[0] + 8) + 0x30))();
              }
            }
            else if (iVar8 != 0) {
              if (DAT_23ed6a4f8 == (code *)0x0) {
                pcVar23 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
              }
              else {
                pcVar20 = *(code **)DAT_23ed6a4f8;
                *(longlong *)DAT_23ed6a4f8 = 1;
                DAT_23ed6a4f8 = pcVar20;
                DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
              }
              pcVar20 = _PyRuntime_exref;
              *(longlong **)(pcVar23 + 0x18) = plVar3;
              *plVar3 = *plVar3 + 1;
              lVar9 = *(longlong *)(pcVar20 + 0x1f8);
              *(undefined4 *)(pcVar23 + 0x20) = 0xffffffff;
              *(int *)(pcVar23 + 0x24) = iVar8;
              lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
              lVar17 = *(longlong *)(pcVar23 + -8);
              puVar2 = *(undefined8 **)(lVar9 + 8);
              *puVar2 = pcVar23 + -0x10;
              *(longlong *)(pcVar23 + -0x10) = lVar9;
              *(ulonglong *)(pcVar23 + -8) = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar2;
              *(code **)(lVar9 + 8) = pcVar23 + -0x10;
              *(code **)(pcVar23 + 0x10) = pcVar22;
              *(longlong *)pcVar22 = *(longlong *)pcVar22 + 1;
              goto joined_r0x00023c65d28f;
            }
            apcStack_e8[0] = pcVar22;
            if (((code *)auStack_f8._0_8_ != pcVar26) && ((code *)auStack_f8._0_8_ != (code *)0x0))
            {
              FUN_23e91b1b0(param_1,auStack_f8,auStack_f8 + 8,apcStack_e8);
            }
            plVar14 = *(longlong **)(auStack_f8._8_8_ + 0x28);
            if (apcStack_e8[0] == pcVar26) {
              pcVar22 = (code *)0x0;
            }
            else {
              pcVar22 = apcStack_e8[0];
              if (apcStack_e8[0] != (code *)0x0) {
                *(longlong *)apcStack_e8[0] = *(longlong *)apcStack_e8[0] + 1;
              }
            }
            *(code **)(auStack_f8._8_8_ + 0x28) = pcVar22;
            if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
              (**(code **)(plVar14[1] + 0x30))();
            }
            plVar14 = *(longlong **)(param_1 + 0x138);
            *(undefined8 *)(param_1 + 0x138) = auStack_f8._8_8_;
            if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
              (**(code **)(plVar14[1] + 0x30))();
            }
            *(longlong *)auStack_f8._0_8_ = *(longlong *)auStack_f8._0_8_ + -1;
            if (*(longlong *)auStack_f8._0_8_ == 0) {
              (**(code **)(*(longlong *)(auStack_f8._0_8_ + 8) + 0x30))();
            }
            if ((apcStack_e8[0] != (code *)0x0) &&
               (*(longlong *)apcStack_e8[0] = *(longlong *)apcStack_e8[0] + -1,
               *(longlong *)apcStack_e8[0] == 0)) {
              (**(code **)(*(longlong *)(apcStack_e8[0] + 8) + 0x30))();
            }
            pcVar20 = *(code **)(param_1 + 0x138);
            apcStack_e8[0] = (code *)0x0;
            auStack_f8 = (undefined1  [16])0x0;
            pcVar22 = *(code **)PyExc_Exception_exref;
            pcVar23 = *(code **)(pcVar20 + 8);
            if ((*(uint *)(*(longlong *)(pcVar22 + 8) + 0xa8) & 0x4000000) == 0) {
              if (((int)*(uint *)(*(longlong *)(pcVar22 + 8) + 0xa8) < 0) &&
                 (((byte)pcVar22[0xab] & 0x40) != 0)) {
                pcVar4 = *(code **)(pcVar23 + 8);
                pcVar1 = pcVar4 + 0xa8;
                if ((*(uint *)pcVar1 & 0x40000000) == 0) {
                  pcVar4 = pcVar23;
                  if (((int)*(uint *)pcVar1 < 0) && (((byte)pcVar23[0xab] & 0x40) != 0)) {
LAB_23c65d435:
                    lVar9 = *(longlong *)(pcVar23 + 0x158);
                    if (lVar9 != 0) {
                      if (*(longlong *)(lVar9 + 0x10) < 1) goto LAB_23c65ce57;
                      lVar17 = 0;
                      while (pcVar22 != *(code **)(lVar9 + 0x18 + lVar17 * 8)) {
                        lVar17 = lVar17 + 1;
                        if (*(longlong *)(lVar9 + 0x10) == lVar17) goto LAB_23c65ce57;
                      }
                      goto LAB_23c65cf67;
                    }
                    do {
                      if (pcVar22 == pcVar23) goto LAB_23c65cf67;
                      pcVar23 = *(code **)(pcVar23 + 0x100);
                      pcVar4 = PyBaseObject_Type_exref;
                    } while (pcVar23 != (code *)0x0);
                  }
                }
                else {
                  pcVar23 = pcVar4;
                  if (*(int *)(*(longlong *)(pcVar4 + 8) + 0xa8) < 0) goto LAB_23c65d435;
                }
                if (pcVar22 != pcVar4) goto LAB_23c65ce57;
              }
              else {
LAB_23c65cf90:
                plVar14 = *(longlong **)PyExc_TypeError_exref;
                uVar21 = PyUnicode_FromString
                                   (
                                   "catching classes that do not inherit from BaseException is not allowed"
                                   );
                plVar16 = *(longlong **)(param_1 + 0x60);
                plVar15 = *(longlong **)(param_1 + 0x68);
                plVar18 = *(longlong **)(param_1 + 0x70);
                *(longlong **)(param_1 + 0x60) = plVar14;
                *plVar14 = *plVar14 + 1;
                *(undefined8 *)(param_1 + 0x68) = uVar21;
                *(undefined8 *)(param_1 + 0x70) = 0;
                if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
                  (**(code **)(plVar16[1] + 0x30))();
                }
                if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                }
                if ((plVar18 == (longlong *)0x0) || (*plVar18 = *plVar18 + -1, *plVar18 != 0))
                goto LAB_23c65cf60;
                (**(code **)(plVar18[1] + 0x30))(plVar18);
                pcVar20 = *(code **)(param_1 + 0x138);
              }
            }
            else {
              lVar9 = *(longlong *)(pcVar22 + 0x10);
              if (lVar9 < 1) {
LAB_23c65ce57:
                pcStack_90 = pcVar20;
                if ((pcVar20 == pcVar26) || (pcVar20 == (code *)0x0)) {
                  plVar14 = *(longlong **)PyExc_RuntimeError_exref;
                  pcVar23 = (code *)PyUnicode_FromString();
                  pcVar20 = *(code **)(param_1 + 0x138);
                  *plVar14 = *plVar14 + 1;
                  iVar8 = 0x1f;
                  *(longlong **)(param_1 + 0x138) = plVar11;
                  pcVar22 = (code *)0x0;
                  if (pcVar20 == (code *)0x0) goto LAB_23c65cef8;
                  iVar8 = 0x1f;
                  pcVar22 = (code *)0x0;
                }
                else {
                  plVar14 = *(longlong **)(pcVar20 + 8);
                  pcVar22 = *(code **)(pcVar20 + 0x28);
                  *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
                  *plVar14 = *plVar14 + 1;
                  pcVar23 = pcVar20;
                  if (pcVar22 == (code *)0x0) {
                    iVar8 = 0;
                    *(longlong **)(param_1 + 0x138) = plVar11;
                  }
                  else {
                    *(longlong *)pcVar22 = *(longlong *)pcVar22 + 1;
                    if (*(longlong **)(pcVar22 + 0x18) == plVar3) {
                      *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar22 + 0x24);
                    }
                    *(longlong **)(param_1 + 0x138) = plVar11;
                    iVar8 = 0;
                  }
                }
                pcStack_88 = (code *)0x0;
                _auStack_98 = (undefined1  [16])0x0;
                *(longlong *)pcVar20 = *(longlong *)pcVar20 + -1;
                if (*(longlong *)pcVar20 == 0) {
                  (**(code **)(*(longlong *)(pcVar20 + 8) + 0x30))();
                }
                goto LAB_23c65cef8;
              }
              lVar17 = 0;
              do {
                if ((-1 < *(int *)(*(longlong *)(*(longlong *)(pcVar22 + lVar17 * 8 + 0x18) + 8) +
                                  0xa8)) ||
                   ((*(byte *)(*(longlong *)(pcVar22 + lVar17 * 8 + 0x18) + 0xab) & 0x40) == 0))
                goto LAB_23c65cf90;
                lVar17 = lVar17 + 1;
              } while (lVar9 != lVar17);
              lVar17 = 0;
              while (iVar8 = FUN_23a35ebd0(param_1,pcVar23,
                                           *(undefined8 *)(pcVar22 + lVar17 * 8 + 0x18)), iVar8 == 0
                    ) {
                lVar17 = lVar17 + 1;
                if (lVar9 == lVar17) {
                  pcVar20 = *(code **)(param_1 + 0x138);
                  goto LAB_23c65ce57;
                }
              }
LAB_23c65cf60:
              pcVar20 = *(code **)(param_1 + 0x138);
            }
LAB_23c65cf67:
            *(longlong **)(param_1 + 0x138) = plVar11;
            plVar11 = plVar13;
            if ((pcVar20 != (code *)0x0) &&
               (*(longlong *)pcVar20 = *(longlong *)pcVar20 + -1, *(longlong *)pcVar20 == 0)) {
              (**(code **)(*(longlong *)(pcVar20 + 8) + 0x30))();
            }
            goto LAB_23c65bfe0;
          }
          *plVar13 = *plVar13 + 1;
          lVar9 = FUN_23ead6720();
          if (lVar9 == 0) goto LAB_23c65d0a5;
LAB_23c65c047:
          plVar11 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23ee28c80);
          if (plVar11 == (longlong *)0x0) {
LAB_23c65cc58:
            pcVar22 = *(code **)(param_1 + 0x70);
            auVar25 = *(undefined1 (*) [8])(param_1 + 0x60);
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcVar26 = _Py_NoneStruct_exref;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            iVar8 = 0x20;
            pcVar23 = *(code **)(param_1 + 0x68);
            goto LAB_23c65cc7e;
          }
          lVar9 = FUN_23ead6720();
          if (lVar9 == 0) {
            FUN_23e915740(param_1,auStack_98,_DAT_23ee28c60);
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
LAB_23c65d300:
              iVar8 = 0x21;
              (**(code **)(plVar11[1] + 0x30))(plVar11);
              pcVar22 = pcStack_88;
              pcVar26 = _Py_NoneStruct_exref;
              auVar25 = auStack_98;
              pcVar23 = pcStack_90;
            }
            else {
              iVar8 = 0x21;
              pcVar22 = pcStack_88;
              pcVar26 = _Py_NoneStruct_exref;
              auVar25 = auStack_98;
              pcVar23 = pcStack_90;
            }
            goto LAB_23c65cc7e;
          }
          plVar14 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23ee28c88);
          lVar9 = _DAT_23ee28c90;
          if (plVar14 == (longlong *)0x0) {
            auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_90 = *(code **)(param_1 + 0x68);
            pcStack_88 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) goto LAB_23c65d300;
            iVar8 = 0x21;
            pcVar22 = pcStack_88;
            pcVar26 = _Py_NoneStruct_exref;
            auVar25 = auStack_98;
            pcVar23 = pcStack_90;
            goto LAB_23c65cc7e;
          }
          *(undefined4 *)(plVar3 + 5) = 0x20;
          lStack_70 = lVar9;
          pcStack_68 = DAT_23ed6ccf0;
          plStack_78 = plVar14;
          plStack_60 = plVar13;
          plVar15 = (longlong *)FUN_23e9583d0(param_1,plVar11,&plStack_78);
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          if (plVar15 == (longlong *)0x0) goto LAB_23c65cc58;
          plVar11 = (longlong *)FUN_23e8d9880(plVar15,DAT_23ed6cd90);
          if (plVar11 == (longlong *)0x0) {
LAB_23c65d2a0:
            pcVar22 = *(code **)(param_1 + 0x70);
            auVar25 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcVar23 = *(code **)(param_1 + 0x68);
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcStack_88 = (code *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            _auStack_98 = (undefined1  [16])0x0;
            *plVar15 = *plVar15 + -1;
            if (*plVar15 == 0) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
            }
            iVar8 = 0x20;
            pcVar26 = _Py_NoneStruct_exref;
            goto LAB_23c65cc7e;
          }
          *(undefined4 *)(plVar3 + 5) = 0x20;
          plVar16 = (longlong *)FUN_23e91a870(param_1,plVar11);
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          if (plVar16 == (longlong *)0x0) goto LAB_23c65d2a0;
          plVar11 = (longlong *)FUN_23e8d9880(plVar15,DAT_23ed6cd98);
          if (plVar11 == (longlong *)0x0) {
            pcVar22 = *(code **)(param_1 + 0x70);
            auVar25 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcVar23 = *(code **)(param_1 + 0x68);
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcVar26 = _Py_NoneStruct_exref;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            iVar8 = 0x20;
LAB_23c65d9c6:
            pcStack_88 = (code *)0x0;
            _auStack_98 = (undefined1  [16])0x0;
            *plVar15 = *plVar15 + -1;
            if (*plVar15 == 0) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
            }
            lVar9 = *plVar16;
            *plVar16 = lVar9 + -1;
            if (lVar9 + -1 == 0) {
              (**(code **)(plVar16[1] + 0x30))();
            }
            if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            goto LAB_23c65cc7e;
          }
          *plVar16 = *plVar16 + 1;
          if ((plStack_110 != (longlong *)0x0) &&
             (lVar9 = *plStack_110, *plStack_110 = lVar9 + -1, lVar9 + -1 == 0)) {
            (**(code **)(plStack_110[1] + 0x30))(plStack_110);
          }
          lVar17 = FUN_23ead6720();
          lVar9 = _DAT_23ee28ca0;
          uVar21 = _DAT_23ee28c98;
          plStack_110 = plVar16;
          if (lVar17 == 0) {
            FUN_23e915740(param_1,auStack_98,_DAT_23ee28c60);
            pcVar22 = pcStack_88;
            auVar25 = auStack_98;
            pcVar23 = pcStack_90;
LAB_23c65c8e3:
            uVar24 = 0x26;
            pcStack_88 = pcVar22;
            auStack_98 = auVar25;
            pcStack_90 = pcVar23;
LAB_23c65c8f8:
            pcVar22 = pcStack_88;
            auStack_b8._8_8_ = pcStack_90;
            auStack_b8._0_8_ = auStack_98;
            pcStack_88 = (code *)0x0;
            auStack_98 = (undefined1  [8])0x0;
            pcStack_90 = (code *)0x0;
            apcStack_a8[0] = pcVar22;
            plVar14 = *(longlong **)(param_1 + 0x138);
            if (plVar14 != (longlong *)0x0) {
              *plVar14 = *plVar14 + 1;
            }
            pcVar23 = DAT_23ed6a4f8;
            if (pcVar22 == (code *)0x0) {
              if (DAT_23ed6a4f8 == (code *)0x0) {
                pcVar23 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
              }
              else {
                pcVar22 = *(code **)DAT_23ed6a4f8;
                *(longlong *)DAT_23ed6a4f8 = 1;
                DAT_23ed6a4f8 = pcVar22;
                DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
              }
              pcVar22 = _PyRuntime_exref;
              *(longlong *)(pcVar23 + 0x10) = 0;
              *(longlong **)(pcVar23 + 0x18) = plVar3;
              *plVar3 = *plVar3 + 1;
              lVar9 = *(longlong *)(pcVar22 + 0x1f8);
              *(undefined4 *)(pcVar23 + 0x24) = uVar24;
              lVar9 = *(longlong *)(lVar9 + 0x10);
              *(undefined4 *)(pcVar23 + 0x20) = 0xffffffff;
              lVar9 = *(longlong *)(lVar9 + 0x2e8);
              lVar17 = *(longlong *)(pcVar23 + -8);
              puVar2 = *(undefined8 **)(lVar9 + 8);
              *puVar2 = pcVar23 + -0x10;
              *(longlong *)(pcVar23 + -0x10) = lVar9;
              *(ulonglong *)(pcVar23 + -8) = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar2;
              *(code **)(lVar9 + 8) = pcVar23 + -0x10;
              if ((apcStack_a8[0] != (code *)0x0) &&
                 (*(longlong *)apcStack_a8[0] = *(longlong *)apcStack_a8[0] + -1,
                 *(longlong *)apcStack_a8[0] == 0)) {
                (**(code **)(*(longlong *)(apcStack_a8[0] + 8) + 0x30))(apcStack_a8[0]);
              }
            }
            else {
              if (DAT_23ed6a4f8 == (code *)0x0) {
                pcVar23 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
              }
              else {
                pcVar26 = *(code **)DAT_23ed6a4f8;
                *(longlong *)DAT_23ed6a4f8 = 1;
                DAT_23ed6a4f8 = pcVar26;
                DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
              }
              pcVar26 = _PyRuntime_exref;
              *(longlong **)(pcVar23 + 0x18) = plVar3;
              *plVar3 = *plVar3 + 1;
              lVar9 = *(longlong *)(pcVar26 + 0x1f8);
              *(undefined4 *)(pcVar23 + 0x24) = uVar24;
              *(undefined4 *)(pcVar23 + 0x20) = 0xffffffff;
              lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
              lVar17 = *(longlong *)(pcVar23 + -8);
              puVar2 = *(undefined8 **)(lVar9 + 8);
              *puVar2 = pcVar23 + -0x10;
              *(longlong *)(pcVar23 + -0x10) = lVar9;
              *(ulonglong *)(pcVar23 + -8) = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar2;
              *(code **)(lVar9 + 8) = pcVar23 + -0x10;
              *(code **)(pcVar23 + 0x10) = pcVar22;
              *(longlong *)pcVar22 = *(longlong *)pcVar22 + 1;
              if ((apcStack_a8[0] != (code *)0x0) &&
                 (*(longlong *)apcStack_a8[0] = *(longlong *)apcStack_a8[0] + -1,
                 *(longlong *)apcStack_a8[0] == 0)) {
                (**(code **)(*(longlong *)(apcStack_a8[0] + 8) + 0x30))();
              }
            }
            pcVar26 = _Py_NoneStruct_exref;
            apcStack_a8[0] = pcVar23;
            if (((code *)auStack_b8._0_8_ != (code *)0x0) &&
               ((code *)auStack_b8._0_8_ != _Py_NoneStruct_exref)) {
              FUN_23e91b1b0(param_1,auStack_b8,auStack_b8 + 8,apcStack_a8);
            }
            plVar18 = *(longlong **)(auStack_b8._8_8_ + 0x28);
            if (apcStack_a8[0] == pcVar26) {
              pcVar22 = (code *)0x0;
            }
            else {
              pcVar22 = apcStack_a8[0];
              if (apcStack_a8[0] != (code *)0x0) {
                *(longlong *)apcStack_a8[0] = *(longlong *)apcStack_a8[0] + 1;
              }
            }
            *(code **)(auStack_b8._8_8_ + 0x28) = pcVar22;
            if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
              (**(code **)(plVar18[1] + 0x30))();
            }
            plVar18 = *(longlong **)(param_1 + 0x138);
            *(undefined8 *)(param_1 + 0x138) = auStack_b8._8_8_;
            if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
              (**(code **)(plVar18[1] + 0x30))();
            }
            *(longlong *)auStack_b8._0_8_ = *(longlong *)auStack_b8._0_8_ + -1;
            if (*(longlong *)auStack_b8._0_8_ == 0) {
              (**(code **)(*(longlong *)(auStack_b8._0_8_ + 8) + 0x30))();
            }
            if ((apcStack_a8[0] != (code *)0x0) &&
               (*(longlong *)apcStack_a8[0] = *(longlong *)apcStack_a8[0] + -1,
               *(longlong *)apcStack_a8[0] == 0)) {
              (**(code **)(*(longlong *)(apcStack_a8[0] + 8) + 0x30))();
            }
            apcStack_a8[0] = (code *)0x0;
            auStack_b8 = (undefined1  [16])0x0;
            iVar8 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                                  *(undefined8 *)PyExc_BaseException_exref);
            if (iVar8 == 0) {
              pcVar20 = *(code **)(param_1 + 0x138);
              pcStack_90 = pcVar20;
              if ((pcVar20 == (code *)0x0) || (pcVar20 == pcVar26)) {
                auVar25 = *(undefined1 (*) [8])PyExc_RuntimeError_exref;
                pcVar23 = (code *)PyUnicode_FromString("No active exception to reraise");
                bVar5 = true;
                pcVar20 = *(code **)(param_1 + 0x138);
                pcVar22 = (code *)0x0;
                *(longlong *)auVar25 = *(longlong *)auVar25 + 1;
                goto LAB_23c65da6f;
              }
              auVar25 = *(undefined1 (*) [8])(pcVar20 + 8);
              pcVar22 = *(code **)(pcVar20 + 0x28);
              *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
              *(longlong *)auVar25 = *(longlong *)auVar25 + 1;
              if (pcVar22 == (code *)0x0) {
                *(longlong **)(param_1 + 0x138) = plVar14;
                bVar5 = true;
                pcVar23 = pcVar20;
                iVar6 = 0;
              }
              else {
                *(longlong *)pcVar22 = *(longlong *)pcVar22 + 1;
                if (*(longlong **)(pcVar22 + 0x18) == plVar3) {
                  *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar22 + 0x24);
                }
                bVar5 = true;
LAB_23c65dbd4:
                *(longlong **)(param_1 + 0x138) = plVar14;
                pcVar23 = pcVar20;
                iVar6 = 0;
              }
LAB_23c65da9e:
              iVar8 = iVar6;
              pcStack_88 = (code *)0x0;
              _auStack_98 = (undefined1  [16])0x0;
              *(longlong *)pcVar20 = *(longlong *)pcVar20 + -1;
              if (*(longlong *)pcVar20 == 0) {
                (**(code **)(*(longlong *)(pcVar20 + 8) + 0x30))();
              }
            }
            else {
              lStack_70 = *(longlong *)(param_1 + 0x138);
              plStack_78 = *(longlong **)(lStack_70 + 8);
              pcStack_68 = *(code **)(lStack_70 + 0x28);
              *(undefined4 *)(plVar3 + 5) = 0x20;
              if (pcStack_68 == (code *)0x0) {
                pcStack_68 = pcVar26;
              }
              plVar18 = (longlong *)FUN_23e956150(param_1,plVar11,&plStack_78);
              if (plVar18 == (longlong *)0x0) {
                pcVar22 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                bVar5 = false;
                pcVar20 = *(code **)(param_1 + 0x138);
                auVar25 = *(undefined1 (*) [8])(param_1 + 0x60);
                pcVar23 = *(code **)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              }
              else {
                iVar8 = FUN_23a35f020(plVar18);
                *plVar18 = *plVar18 + -1;
                if (*plVar18 == 0) {
                  (**(code **)(plVar18[1] + 0x30))(plVar18);
                }
                if (iVar8 == -1) {
                  auVar25 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcVar23 = *(code **)(param_1 + 0x68);
                  bVar5 = false;
                  pcVar22 = *(code **)(param_1 + 0x70);
                  pcVar20 = *(code **)(param_1 + 0x138);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                }
                else {
                  if (iVar8 != 0) {
                    plVar18 = *(longlong **)(param_1 + 0x138);
                    *(longlong **)(param_1 + 0x138) = plVar14;
                    if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
                      (**(code **)(plVar18[1] + 0x30))();
                    }
                    goto LAB_23c65cbb8;
                  }
                  pcVar20 = *(code **)(param_1 + 0x138);
                  pcStack_90 = pcVar20;
                  bVar5 = false;
                  if ((pcVar20 != pcVar26) && (pcVar20 != (code *)0x0)) {
                    auVar25 = *(undefined1 (*) [8])(pcVar20 + 8);
                    pcVar22 = *(code **)(pcVar20 + 0x28);
                    *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
                    *(longlong *)auVar25 = *(longlong *)auVar25 + 1;
                    if (pcVar22 != (code *)0x0) {
                      *(longlong *)pcVar22 = *(longlong *)pcVar22 + 1;
                      if (*(longlong **)(pcVar22 + 0x18) == plVar3) {
                        *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar22 + 0x24);
                      }
                      goto LAB_23c65dbd4;
                    }
                    *(longlong **)(param_1 + 0x138) = plVar14;
                    pcVar23 = pcVar20;
                    iVar6 = 0;
                    goto LAB_23c65da9e;
                  }
                  auVar25 = *(undefined1 (*) [8])PyExc_RuntimeError_exref;
                  pcVar23 = (code *)PyUnicode_FromString("No active exception to reraise");
                  pcVar20 = *(code **)(param_1 + 0x138);
                  pcVar22 = (code *)0x0;
                  *(longlong *)auVar25 = *(longlong *)auVar25 + 1;
                }
              }
LAB_23c65da6f:
              iVar8 = 0x20;
              *(longlong **)(param_1 + 0x138) = plVar14;
              iVar6 = 0x20;
              if (pcVar20 != (code *)0x0) goto LAB_23c65da9e;
            }
            pcStack_88 = (code *)0x0;
            _auStack_98 = (undefined1  [16])0x0;
            plStack_d8 = (longlong *)auVar25;
            pcStack_d0 = pcVar23;
            pcStack_c8 = pcVar22;
            if (bVar5) {
              *(undefined4 *)(plVar3 + 5) = 0x20;
              plVar14 = (longlong *)FUN_23e957a30(param_1,plVar11,_DAT_23ee28cb0);
              if (plVar14 == (longlong *)0x0) {
                pcStack_88 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                iVar8 = 0x20;
                auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
                pcStack_90 = *(code **)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                FUN_23a35d6b0(&plStack_d8);
                pcVar22 = pcStack_88;
                auVar25 = auStack_98;
                pcVar23 = pcStack_90;
              }
              else {
                *plVar14 = *plVar14 + -1;
                pcVar22 = pcStack_c8;
                auVar25 = (undefined1  [8])plStack_d8;
                pcVar23 = pcStack_d0;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                  pcVar22 = pcStack_c8;
                  auVar25 = (undefined1  [8])plStack_d8;
                  pcVar23 = pcStack_d0;
                }
              }
            }
            goto LAB_23c65d9c6;
          }
          *(undefined4 *)(plVar3 + 5) = 0x26;
          lStack_70 = lVar9;
          plStack_78 = plVar16;
          plVar14 = (longlong *)FUN_23e954670(param_1,lVar17,uVar21,&plStack_78);
          if (plVar14 == (longlong *)0x0) {
LAB_23c65d400:
            auVar25 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcVar22 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            pcVar23 = *(code **)(param_1 + 0x68);
            goto LAB_23c65c8e3;
          }
          plVar18 = (longlong *)FUN_23a388310(plVar14);
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          if (plVar18 == (longlong *)0x0) goto LAB_23c65d400;
          plVar14 = (longlong *)(**(code **)(plVar18[1] + 0xe0))(plVar18);
          if (plVar14 == (longlong *)0x0) {
            plVar14 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,0,2);
            plVar19 = (longlong *)0x0;
            if (plVar14 != (longlong *)0x0) goto LAB_23c65c241;
LAB_23c65c84f:
            pcVar22 = pcStack_88;
            pcVar23 = pcStack_90;
            auVar25 = auStack_98;
            pcStack_88 = (code *)0x0;
            _auStack_98 = (undefined1  [16])0x0;
            *plVar18 = *plVar18 + -1;
            if (*plVar18 == 0) {
              (**(code **)(plVar18[1] + 0x30))(plVar18);
            }
            pcStack_88 = (code *)0x0;
            auStack_98 = (undefined1  [8])0x0;
            pcStack_90 = (code *)0x0;
            if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
              (**(code **)(plVar19[1] + 0x30))(plVar19);
            }
            goto LAB_23c65c8e3;
          }
LAB_23c65c241:
          plVar19 = (longlong *)(**(code **)(plVar18[1] + 0xe0))(plVar18);
          if (((plVar19 == (longlong *)0x0) &&
              (plVar19 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,1,2),
              plVar19 == (longlong *)0x0)) ||
             (cVar7 = FUN_23a3884a0(param_1,auStack_98,plVar18,2), cVar7 == '\0'))
          goto LAB_23c65c84f;
          *plVar18 = *plVar18 + -1;
          if (*plVar18 == 0) {
            (**(code **)(plVar18[1] + 0x30))(plVar18);
          }
          lVar9 = *plVar14;
          *plVar14 = lVar9 + 1;
          if (plStack_128 != (longlong *)0x0) {
            lVar9 = *plStack_128;
            *plStack_128 = lVar9 + -1;
            if (lVar9 + -1 == 0) {
              (**(code **)(plStack_128[1] + 0x30))(plStack_128);
              lVar9 = *plVar14 + -1;
            }
            else {
              lVar9 = *plVar14 + -1;
            }
          }
          *plVar14 = lVar9;
          if (lVar9 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          lVar9 = *plVar19;
          *plVar19 = lVar9 + 1;
          if (plStack_120 != (longlong *)0x0) {
            lVar9 = *plStack_120;
            *plStack_120 = lVar9 + -1;
            if (lVar9 + -1 == 0) {
              (**(code **)(plStack_120[1] + 0x30))(plStack_120);
            }
            lVar9 = *plVar19 + -1;
          }
          *plVar19 = lVar9;
          if (lVar9 == 0) {
            (**(code **)(plVar19[1] + 0x30))(plVar19);
          }
          iVar8 = FUN_23a35f020(plVar14);
          plStack_128 = plVar14;
          plStack_120 = plVar19;
          if (iVar8 == -1) {
            auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_88 = *(code **)(param_1 + 0x70);
            uVar24 = 0x27;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            pcStack_90 = *(code **)(param_1 + 0x68);
            goto LAB_23c65c8f8;
          }
          if (iVar8 != 0) {
            plVar14 = (longlong *)FUN_23e8bd350(plVar14);
            if (plVar14 != (longlong *)0x0) {
              plVar18 = (longlong *)FUN_23e8bc2f0(plVar14,_DAT_23ee28ca8);
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                (**(code **)(plVar14[1] + 0x30))(plVar14);
              }
              if (plVar18 != (longlong *)0x0) {
                *(undefined4 *)(plVar3 + 5) = 0x28;
                plVar14 = (longlong *)FUN_23e91a870(param_1);
                *plVar18 = *plVar18 + -1;
                if (*plVar18 == 0) {
                  (**(code **)(plVar18[1] + 0x30))(plVar18);
                }
                if (plVar14 != (longlong *)0x0) {
                  *(undefined4 *)(plVar3 + 5) = 0x20;
                  plVar18 = (longlong *)FUN_23e957a30(param_1,plVar11,_DAT_23ee28cb0);
                  if (plVar18 != (longlong *)0x0) {
                    *plVar18 = *plVar18 + -1;
                    if (*plVar18 == 0) {
                      FUN_23a334bc0();
                    }
                    *plVar15 = *plVar15 + -1;
                    if (*plVar15 == 0) {
                      FUN_23a334bc0(plVar15);
                    }
                    lVar9 = *plVar16;
                    *plVar16 = lVar9 + -1;
                    if (lVar9 + -1 == 0) {
                      FUN_23a334bc0(plVar16);
                    }
                    *plVar11 = *plVar11 + -1;
                    if (*plVar11 == 0) {
                      FUN_23a334bc0(plVar11);
                    }
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      FUN_23a334bc0(plVar13);
                    }
                    lVar9 = *plVar12;
                    *plVar12 = lVar9 + -1;
                    if (lVar9 + -1 == 0) {
                      FUN_23a334bc0(plVar12);
                    }
                    FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      (**(code **)(plVar10[1] + 0x30))(plVar10);
                      goto LAB_23c65d8ca;
                    }
                    lVar9 = *plVar13;
                    *plVar13 = lVar9 + -1;
                    if (lVar9 + -1 == 0) goto LAB_23c65d8d1;
                    goto LAB_23c65d8eb;
                  }
                  goto LAB_23c65c448;
                }
              }
            }
            auStack_98 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_88 = *(code **)(param_1 + 0x70);
            uVar24 = 0x28;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            pcStack_90 = *(code **)(param_1 + 0x68);
            goto LAB_23c65c8f8;
          }
          *(undefined4 *)(plVar3 + 5) = 0x20;
          plVar14 = (longlong *)FUN_23e957a30(param_1,plVar11,_DAT_23ee28cb0);
          if (plVar14 == (longlong *)0x0) {
LAB_23c65c448:
            iVar8 = 0x20;
            auVar25 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcVar22 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcVar26 = _Py_NoneStruct_exref;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            pcVar23 = *(code **)(param_1 + 0x68);
            goto LAB_23c65d9c6;
          }
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))();
          }
LAB_23c65cbb8:
          *plVar15 = *plVar15 + -1;
          if (*plVar15 == 0) {
            (**(code **)(plVar15[1] + 0x30))();
          }
          lVar9 = *plVar16;
          *plVar16 = lVar9 + -1;
          if (lVar9 + -1 == 0) {
            (**(code **)(plVar16[1] + 0x30))();
          }
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))();
          }
          lVar9 = *(longlong *)(param_1 + 0x10);
          if ((((*(int *)(*(longlong *)(lVar9 + 0x28) + 0x160) != 0) ||
               (*(int *)(lVar9 + 0x78) != 0)) && (iVar8 = Py_MakePendingCalls(), iVar8 < 0)) &&
             (*(longlong *)(param_1 + 0x60) != 0)) goto LAB_23c65e2a3;
          if (*(int *)(lVar9 + 0x68) != 0) {
            PyEval_SaveThread();
            PyEval_AcquireThread(param_1);
          }
          plVar14 = *(longlong **)(param_1 + 0x90);
          plVar11 = plVar13;
        } while (plVar14 == (longlong *)0x0);
        plVar11 = *(longlong **)(param_1 + 0x60);
        plVar16 = *(longlong **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x90) = 0;
        plVar15 = *(longlong **)(param_1 + 0x70);
        *(longlong **)(param_1 + 0x60) = plVar14;
        *plVar14 = *plVar14 + 1;
        *(undefined8 *)(param_1 + 0x68) = 0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
          (**(code **)(plVar11[1] + 0x30))();
        }
        if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
          (**(code **)(plVar16[1] + 0x30))();
        }
        if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
          (**(code **)(plVar15[1] + 0x30))();
        }
LAB_23c65e2a3:
        pcVar22 = *(code **)(param_1 + 0x70);
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar23 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        iVar8 = 0x1e;
LAB_23c65cef8:
        pcStack_88 = (code *)0x0;
        _auStack_98 = (undefined1  [16])0x0;
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))();
        }
LAB_23c65cf08:
        plVar11 = plVar13;
        lVar9 = *plVar12;
        *plVar12 = lVar9 + -1;
        if (lVar9 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))();
        }
        pcStack_88 = pcVar22;
        auStack_98 = (undefined1  [8])plVar14;
        pcStack_90 = pcVar23;
        if (pcVar22 == (code *)0x0) {
          if (iVar8 == 0) {
            iVar8 = (int)plVar3[5];
          }
          goto LAB_23c65d59f;
        }
        if (*(longlong **)(pcVar22 + 0x18) == plVar3) goto LAB_23c65c699;
        if (iVar8 == 0) {
          iVar8 = (int)plVar3[5];
        }
      }
    }
LAB_23c65c5a9:
    pcVar23 = pcStack_88;
    pcVar22 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar22 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar26 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar26;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar26 = _PyRuntime_exref;
    *(longlong **)(pcVar22 + 0x18) = plVar3;
    *plVar3 = *plVar3 + 1;
    lVar9 = *(longlong *)(pcVar26 + 0x1f8);
    *(int *)(pcVar22 + 0x24) = iVar8;
    *(undefined4 *)(pcVar22 + 0x20) = 0xffffffff;
    lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
    lVar17 = *(longlong *)(pcVar22 + -8);
    puVar2 = *(undefined8 **)(lVar9 + 8);
    *puVar2 = pcVar22 + -0x10;
    *(longlong *)(pcVar22 + -0x10) = lVar9;
    *(ulonglong *)(pcVar22 + -8) = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar2;
    *(code **)(lVar9 + 8) = pcVar22 + -0x10;
    *(code **)(pcVar22 + 0x10) = pcVar23;
    *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
    pcVar23 = pcStack_88;
  }
  if ((pcVar23 != (code *)0x0) &&
     (*(longlong *)pcVar23 = *(longlong *)pcVar23 + -1, *(longlong *)pcVar23 == 0)) {
    (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))();
  }
LAB_23c65c699:
  pcStack_88 = pcVar22;
  FUN_23e8bba40(plVar3,"ooooo",plVar10,plVar11,plStack_110,plStack_128,plStack_120);
  if (_DAT_23ee29da0 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23ee29da0 = (longlong *)0x0;
  }
  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar9 + 0x28);
  plVar12 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar12 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  pcVar23 = pcStack_88;
  pcVar22 = pcStack_90;
  auVar25 = auStack_98;
  plVar3[0xf] = 0;
  _auStack_98 = (undefined1  [16])0x0;
  pcStack_88 = (code *)0x0;
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plStack_110 != (longlong *)0x0) && (*plStack_110 = *plStack_110 + -1, *plStack_110 == 0)) {
    (**(code **)(plStack_110[1] + 0x30))(plStack_110);
  }
  if ((plStack_128 != (longlong *)0x0) &&
     (lVar9 = *plStack_128, *plStack_128 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(plStack_128[1] + 0x30))(plStack_128);
  }
  if ((plStack_120 != (longlong *)0x0) &&
     (lVar9 = *plStack_120, *plStack_120 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(plStack_120[1] + 0x30))(plStack_120);
  }
  _auStack_98 = CONCAT88(pcVar22,auVar25);
  pcStack_88 = pcVar23;
  FUN_23a33aa70(param_1,auVar25,pcVar22,pcVar23);
  return (longlong *)0x0;
}
